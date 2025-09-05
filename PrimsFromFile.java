import java.io.*;
import java.util.*;

public class PrimsFromFile {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            // Ask user for file name
            System.out.print("Enter the file name containing the cost matrix: ");
            String fileName = sc.nextLine();

            // Read matrix from file
            List<int[]> matrixList = new ArrayList<>();
            Scanner fileScanner = new Scanner(new File(fileName));

            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine().trim();
                if (!line.isEmpty()) {
                    String[] parts = line.split("\\s+");
                    int[] row = new int[parts.length];
                    for (int i = 0; i < parts.length; i++) {
                        row[i] = Integer.parseInt(parts[i]);
                    }
                    matrixList.add(row);
                }
            }
            fileScanner.close();

            int n = matrixList.size();
            int[][] graph = new int[n][n];
            for (int i = 0; i < n; i++) {
                graph[i] = matrixList.get(i);
            }

            // Run Prim's Algorithm
            primsAlgorithm(graph, n);

        } catch (FileNotFoundException e) {
            System.out.println("File not found. Please check the file name and path.");
        }
    }

    public static void primsAlgorithm(int[][] graph, int n) {
        int[] key = new int[n];          // Min weight to connect a node
        boolean[] mstSet = new boolean[n]; // Track included vertices
        int[] parent = new int[n];       // Store constructed MST

        // Initialize all keys as infinity
        Arrays.fill(key, Integer.MAX_VALUE);
        key[0] = 0;    // Start from first vertex
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) {
            int u = minKey(key, mstSet, n);
            mstSet[u] = true;

            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        printMST(parent, graph, n);
    }

    // Function to find the vertex with the minimum key value
    public static int minKey(int[] key, boolean[] mstSet, int n) {
        int min = Integer.MAX_VALUE, minIndex = -1;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    // Print the constructed MST
    public static void printMST(int[] parent, int[][] graph, int n) {
        System.out.println("\nEdges in the Minimum Spanning Tree (MST):");
        int totalCost = 0;
        for (int i = 1; i < n; i++) {
            System.out.println(parent[i] + " - " + i + " : " + graph[i][parent[i]]);
            totalCost += graph[i][parent[i]];
        }
        System.out.println("Total cost of setting up cables: " + totalCost);
    }
}
