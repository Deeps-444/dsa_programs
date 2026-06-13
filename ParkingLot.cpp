#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include <mutex>

enum class VehicleType
{
    MOTORCYCLE,
    CAR,
    TRUCK
};
enum class SlotType
{
    SMALL,
    MEDIUM,
    LARGE
};
enum class TicketStatus
{
    ACTIVE,
    PAID
};

// Strategy Pattern for Fee Calculation
class ParkingFeeStrategy
{
public:
    virtual ~ParkingFeeStrategy() = default;
    virtual double calculateFee(long hours, VehicleType type) = 0;
};

class DefaultFeeStrategy : public ParkingFeeStrategy
{
public:
    double calculateFee(long hours, VehicleType type) override
    {
        if (hours <= 0)
            hours = 1; // Minimum 1-hour charge
        switch (type)
        {
        case VehicleType::MOTORCYCLE:
            return hours * 10.0;
        case VehicleType::CAR:
            return hours * 20.0;
        case VehicleType::TRUCK:
            return hours * 50.0;
        default:
            return hours * 15.0;
        }
    }
};

class Vehicle
{
protected:
    std::string licensePlate;
    VehicleType type;

public:
    Vehicle(std::string plate, VehicleType t) : licensePlate(plate), type(t) {}
    virtual ~Vehicle() = default;
    VehicleType getType() const { return type; }
    std::string getPlate() const { return licensePlate; }
};

class Car : public Vehicle
{
public:
    Car(std::string plate) : Vehicle(plate, VehicleType::CAR) {}
};

// Represents an individual slot
class ParkingSlot
{
private:
    int slotNumber;
    SlotType slotType;
    bool isOccupied;
    std::shared_ptr<Vehicle> parkedVehicle;

public:
    ParkingSlot(int num, SlotType type) : slotNumber(num), slotType(type), isOccupied(false), parkedVehicle(nullptr) {}

    bool isAvailable() const { return !isOccupied; }
    SlotType getSlotType() const { return slotType; }
    int getSlotNumber() const { return slotNumber; }

    bool parkVehicle(std::shared_ptr<Vehicle> v)
    {
        if (isOccupied)
            return false;
        parkedVehicle = v;
        isOccupied = true;
        return true;
    }

    void unparkVehicle()
    {
        parkedVehicle = nullptr;
        isOccupied = false;
    }
};

class ParkingLot
{
private:
    std::string name;
    std::vector<std::unique_ptr<ParkingFloor>> floors;
    std::unique_ptr<ParkingFeeStrategy> feeStrategy;
    std::mutex mtx; // Thread safety

    // Singleton implementation
    ParkingLot() : name("Core CareSync Parking Hub"), feeStrategy(std::make_unique<DefaultFeeStrategy>()) {}

public:
    static ParkingLot &getInstance()
    {
        static ParkingLot instance;
        return instance;
    }

    // Delete copy constructors
    ParkingLot(const ParkingLot &) = delete;
    ParkingLot &operator=(const ParkingLot &) = delete;

    void addFloor(int numSlots)
    {
        int nextFloorNum = floors.size() + 1;
        floors.push_back(std::make_unique<ParkingFloor>(nextFloorNum, numSlots));
    }

    std::shared_ptr<Ticket> entryGateHandle(std::shared_ptr<Vehicle> vehicle)
    {
        std::lock_guard<std::mutex> lock(mtx);

        for (auto &floor : floors)
        {
            auto slot = floor->findAvailableSlot(vehicle->getType());
            if (slot)
            {
                slot->parkVehicle(vehicle);

                auto ticket = std::make_shared<Ticket>();
                ticket->ticketId = "TKT-" + vehicle->getPlate() + "-" + std::to_string(rand() % 1000);
                ticket->vehicle = vehicle;
                ticket->slot = slot;
                ticket->floorNumber = floor->getFloorNumber();
                ticket->entryTime = std::chrono::system_clock::now();
                ticket->status = TicketStatus::ACTIVE;

                std::cout << "[ENTRY] " << vehicle->getPlate() << " parked at Floor "
                          << ticket->floorNumber << ", Slot " << slot->getSlotNumber() << "\n";
                return ticket;
            }
        }
        std::cout << "[ENTRY] Sorry, Parking Lot is full for vehicle: " << vehicle->getPlate() << "\n";
        return nullptr;
    }

    void exitGateHandle(std::shared_ptr<Ticket> ticket)
    {
        if (!ticket || ticket->status == TicketStatus::PAID)
            return;

        std::lock_guard<std::mutex> lock(mtx);

        // Simulate time passing (e.g., 3 hours later)
        long durationHours = 3;

        double dynamicCost = feeStrategy->calculateFee(durationHours, ticket->vehicle->getType());
        ticket->slot->unparkVehicle();
        ticket->status = TicketStatus::PAID;

        std::cout << "[EXIT] " << ticket->vehicle->getPlate() << " leaving Floor " << ticket->floorNumber
                  << ". Parked for " << durationHours << " hours. Total Bill: ₹" << dynamicCost << "\n";
    }
};

int main()
{
    // Seed for ticket random strings
    srand(time(0));

    // Initialize the Parking Lot System
    ParkingLot &myParkingLot = ParkingLot::getInstance();
    myParkingLot.addFloor(10); // Floor 1 setup
    myParkingLot.addFloor(10); // Floor 2 setup

    // Create Vehicles
    auto car1 = std::make_shared<Car>("MH-12-AB-1234");
    auto bike1 = std::make_shared<Vehicle>("MH-14-XYZ-9876", VehicleType::MOTORCYCLE);

    std::cout << "--- Simulation Started ---\n";

    // Vehicles arriving at Entry Gate
    auto ticket1 = myParkingLot.entryGateHandle(car1);
    auto ticket2 = myParkingLot.entryGateHandle(bike1);

    std::cout << "\n--- Time Passes ---\n\n";

    // Vehicles leaving via Exit Gate
    if (ticket1)
        myParkingLot.exitGateHandle(ticket1);
    if (ticket2)
        myParkingLot.exitGateHandle(ticket2);

    return 0;
}