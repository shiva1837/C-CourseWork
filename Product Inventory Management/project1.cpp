/********************************************************************************************/
/*  Author: Shivamani Jadi 
 *  Major:  Computer Science 
 *  Creation Date: 02/10/2025
 *  Section: 010
 *  Due Date: 02/17/2025
 *  Professor Name: Yong Zhang
 *  Assignment: Project #1  
 *  Purpose: This program reads product data from a file, stores it in a struct array,
 *           and performs tasks such as displaying product details, identifying the most
 *           expensive product, and finding products with the lowest stock level.               
 ********************************************************************************************/

 #include <iostream>  // For input and output
 #include <fstream>   // For file input and output
 #include <iomanip>   // For formatting output
 
 using namespace std;
 
 struct ProductType {
     string productName; // Name of the product
     string category;    // Category of the product
     double price;       // Price of the product
     int stock;          // Stock level of the product
 };
 
 const int MAX_PRODUCTS = 15; // Maximum number of products in the product array
 
 // Function prototypes
 void displayProducts(const ProductType products[], int size);             
 void findMostExpensiveProduct(const ProductType products[], int size);           
 void findLowestStockProducts(const ProductType products[], int size);  
 
 int main() {
     // Array to store product data
    ProductType products[MAX_PRODUCTS]; 
    
    // Open the input data file for reading
    ifstream inputFile("productData.txt");  // Open the file

    // Check if the file was successfully opened
    if (!inputFile) {
        cout << "Error: Unable to open the input data file!" << endl;
        return 1; // Exit the program with an error code
    }

    // Read product data from file
    int count = 0;

    while (count < MAX_PRODUCTS && inputFile >> products[count].productName >> products[count].category >> products[count].price >> products[count].stock) {
        count++;
    }

    inputFile.close(); // Close the file
 
     displayProducts(products, count);
     findMostExpensiveProduct(products, count);
     findLowestStockProducts(products, count);
 
     return 0;
 }
 
 // Function to display all product details
 void displayProducts(const ProductType products[], int size) {
    cout << left << setw(15) << "Product Name" << setw(15) << "Category" << setw(10) << "Price" << "Stock" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << products[i].productName << setw(15) << products[i].category << fixed << setprecision(2) << setw(10) << products[i].price << products[i].stock << endl;
    }
    cout << endl;
}
 
 // Function to find and display the most expensive product
 void findMostExpensiveProduct(const ProductType products[], int size) {
     int maxIndex = 0;
     
     for (int i = 1; i < size; i++) {
         if (products[i].price > products[maxIndex].price) {
             maxIndex = i;
         }
     }
 
     cout << "\nMost Expensive Product:\n";
     cout << products[maxIndex].productName << ", " 
          << products[maxIndex].category << ", $" 
          << fixed << setprecision(2) << products[maxIndex].price << endl;
 }
 
 // Function to find and display products with the lowest stock
 void findLowestStockProducts(const ProductType products[], int size) {
     int minStock = products[0].stock;
 
     for (int i = 1; i < size; i++) {
         if (products[i].stock < minStock) {
             minStock = products[i].stock;
         }
     }
 
     cout << "\nProduct(s) with Lowest Stock:\n";
     for (int i = 0; i < size; i++) {
         if (products[i].stock == minStock) {
             cout << products[i].productName << ", " 
                  << products[i].category << ", Stock: " 
                  << products[i].stock << endl;
         }
     }
 } 