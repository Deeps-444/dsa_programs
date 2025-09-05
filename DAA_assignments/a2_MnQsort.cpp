#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <chrono>

using namespace std;

time_t parseTimestamp(const string &ts)
{
    struct tm tmStruct = {};
    strptime(ts.c_str(), "%Y-%m-%d %H:%M:%S", &tmStruct);
    return mktime(&tmStruct);
}

string formatTimeStamp(time_t t)
{
    char time_r[20];
    strftime(time_r, sizeof(time_r), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return string(time_r);
}

class Customer
{
protected:
    int customerID;
    string customerName;
    double balance;

public:
    Customer() {}
    Customer(int id, string name, double balance)
    {
        customerID = id;
        customerName = name;
        this->balance = balance;
    }
};

class Transaction : public Customer
{
private:
    int transactionID;
    int transactionAMt;
    time_t timeStamp;

public:
    Transaction() {}
    Transaction(int tid, int id, string name, double bal, double amt, time_t ts)
    {
        transactionID = tid;
        customerID = id;
        customerName = name;
        balance = bal;
        transactionAMt = amt;
        timeStamp = ts;
    }

    int getTransactionID() const
    {
        return transactionID;
    }

    int getCustomerID() const
    {
        return customerID;
    }

    string getCustomerName() const
    {
        return customerName;
    }

    double getBalance() const
    {
        return balance;
    }

    double getTransactionAmt() const
    {
        return transactionAMt;
    }

    time_t getTimeStamp() const
    {
        return timeStamp;
    }
};

// swap function

void swap(Transaction *a, Transaction *b)
{
    Transaction temp = *a;
    *a = *b;
    *b = temp;
}

// quick sort ----
int partitions(vector<Transaction> &arr, int low, int high)
{
    time_t pivot = arr[high].getTransactionAmt();
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].getTransactionAmt() <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Transaction> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partitions(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// merge sort ----
void merge(vector<Transaction> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Transaction> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + n1];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].getTransactionAmt() <= R[j].getTransactionAmt())
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<Transaction> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ouput file
void writeFile(const string &f, const vector<Transaction> &arr)
{
    ofstream file(f);
    if (!file.is_open())
    {
        cerr << "File is not opening!" << endl;
        return;
    }
    file << "TransactionID, CustomerID, CustomerName, Balance, TransactionAmount, TimeStamp\n";
    for (auto &tx : arr)
    {
        file << tx.getTransactionID() << ","
             << tx.getCustomerID() << ","
             << tx.getCustomerName() << ","
             << tx.getBalance() << ","
             << tx.getTransactionAmt() << ","
             << formatTimeStamp(tx.getTimeStamp()) << "\n";
    }
    file.close();
}

int main()
{
    string inputFile;
    cout << "Enter the inputFile: ";
    cin >> inputFile;
    ifstream file(inputFile);
    if (!file.is_open())
    {
        cerr << "File is not opening!" << endl;
        return 1;
    }

    vector<Transaction> arr;

    // input--
    string line;
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        string tID, cID, cName, balstr, amtstr, tsstr;

        getline(ss, tID, ',');
        getline(ss, cID, ',');
        getline(ss, cName, ',');
        getline(ss, balstr, ',');
        getline(ss, amtstr, ',');
        getline(ss, tsstr);

        if (balstr.empty() || amtstr.empty())
        {
            continue;
        }

        double balance = stod(balstr);
        double transactionAmt = stod(amtstr);

        Transaction tx(stoi(tID), stoi(cID), cName, stod(balstr), stod(amtstr), parseTimestamp(tsstr));
        arr.emplace_back(tx);
    }

    vector<Transaction> quickArr = arr;
    vector<Transaction> mergeArr = arr;

    // quick sort timing
    auto start = chrono::high_resolution_clock::now();
    quickSort(quickArr, 0, quickArr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    double quickTime = chrono::duration<double>(end - start).count();

    // merge sort timing
    start = chrono::high_resolution_clock::now();
    mergeSort(quickArr, 0, quickArr.size() - 1);
    end = chrono::high_resolution_clock::now();
    double mergeTime = chrono::duration<double>(end - start).count();

    string quickfile, mergefile;
    cout << "Enter output file for quick sort: ";
    cin >> quickfile;
    cout << "Enter output file for mergesort: ";
    cin >> mergefile;

    writeFile(quickfile, quickArr);
    writeFile(mergefile, mergeArr);

    cout << "Quick Sort Time: " << quickTime << "secs\n";
    cout << "Merge Sort Time: " << mergeTime << "secs\n";
    file.close();
    return 0;
}