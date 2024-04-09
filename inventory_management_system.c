#include <stdio.h>
#include <string.h>

// Define structures for product, supplier, and transaction details
struct Product
{
    int productId;
    char productName[50];
    float productPrice;
    int quantity;
};

struct Supplier
{
    int supplierId;
    char supplierName[50];
    char supplierAddress[100];
};

struct Transaction
{
    int transactionId;
    int productId;
    int quantity;
    char transactionDate[20];
};

// Global arrays to store data
struct Product products[100];
int productCount = 0;

struct Supplier suppliers[100];
int supplierCount = 0;

struct Transaction transactions[100];
int transactionCount = 0;

// Function prototypes
void addProduct();
void updateProduct();
void deleteProduct();
void displayProductDetails();
void addSupplier();
void updateSupplier();
void deleteSupplier();
void displaySupplierDetails();
void recordTransaction();
void updateTransaction();
void displayTransactionHistory();

int main()
{
    int choice;
    do
    {
        // Display menu options
        printf("Inventory Management System\n");
        printf("1. Product Details\n");
        printf("2. Supplier Details\n");
        printf("3. Transaction Details\n");
        printf("4. Enter q to quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice)
        {
        case 1:
            // Product details menu
            printf("Product Details Menu\n");
            printf("1. Add Product\n");
            printf("2. Update Product\n");
            printf("3. Delete Product\n");
            printf("4. Display Product Details\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                displayProductDetails();
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 2:
            // Supplier details menu
            printf("Supplier Details Menu\n");
            printf("1. Add Supplier\n");
            printf("2. Update Supplier\n");
            printf("3. Delete Supplier\n");
            printf("4. Display Supplier Details\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                addSupplier();
                break;
            case 2:
                updateSupplier();
                break;
            case 3:
                deleteSupplier();
                break;
            case 4:
                displaySupplierDetails();
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 3:
            // Transaction details menu
            printf("Transaction Details Menu\n");
            printf("1. Record Transaction\n");
            printf("2. Update Transaction\n");
            printf("3. Display Transaction History\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                recordTransaction();
                break;
            case 2:
                updateTransaction();
                break;
            case 3:
                displayTransactionHistory();
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 'q':
            printf("=== exitting ===\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice = 'q');
    return 0;
}

// Product details module functions
void addProduct()
{
    struct Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.productId);
    printf("Enter product name: ");
    scanf("%s", newProduct.productName);
    printf("Enter product price: ");
    scanf("%f", &newProduct.productPrice);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    products[productCount++] = newProduct;
    printf("Product added successfully\n");
}

void updateProduct()
{
    int productId, index = -1;
    printf("Enter product ID to update: ");
    scanf("%d", &productId);
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].productId == productId)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("Enter new product name: ");
        scanf("%s", products[index].productName);
        printf("Enter new product price: ");
        scanf("%f", &products[index].productPrice);
        printf("Enter new quantity: ");
        scanf("%d", &products[index].quantity);
        printf("Product updated successfully\n");
    }
    else
    {
        printf("Product not found\n");
    }
}

void deleteProduct()
{
    int productId, index = -1;
    printf("Enter product ID to delete: ");
    scanf("%d", &productId);
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].productId == productId)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < productCount - 1; i++)
        {
            products[i] = products[i + 1];
        }
        productCount--;
        printf("Product deleted successfully\n");
    }
    else
    {
        printf("Product not found\n");
    }
}

void displayProductDetails()
{
    printf("Product Details\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++)
    {
        printf("%d\t%s\t%.2f\t%d\n", products[i].productId, products[i].productName, products[i].productPrice, products[i].quantity);
    }
}
// Supplier details module functions
void addSupplier()
{
    struct Supplier newSupplier;
    printf("Enter supplier ID: ");
    scanf("%d", &newSupplier.supplierId);
    printf("Enter supplier name: ");
    scanf("%s", newSupplier.supplierName);
    printf("Enter supplier address: ");
    scanf("%s", newSupplier.supplierAddress);
    suppliers[supplierCount++] = newSupplier;
    printf("Supplier added successfully\n");
}

void updateSupplier()
{
    int supplierId, index = -1;
    printf("Enter supplier ID to update: ");
    scanf("%d", &supplierId);
    for (int i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierId == supplierId)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("Enter new supplier name: ");
        scanf("%s", suppliers[index].supplierName);
        printf("Enter new supplier address: ");
        scanf("%s", suppliers[index].supplierAddress);
        printf("Supplier updated successfully\n");
    }
    else
    {
        printf("Supplier not found\n");
    }
}

void deleteSupplier()
{
    int supplierId, index = -1;
    printf("Enter supplier ID to delete: ");
    scanf("%d", &supplierId);
    for (int i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierId == supplierId)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < supplierCount - 1; i++)
        {
            suppliers[i] = suppliers[i + 1];
        }
        supplierCount--;
        printf("Supplier deleted successfully\n");
    }
    else
    {
        printf("Supplier not found\n");
    }
}

void displaySupplierDetails()
{
    printf("Supplier Details\n");
    printf("ID\tName\tAddress\n");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("%d\t%s\t%s\n", suppliers[i].supplierId, suppliers[i].supplierName, suppliers[i].supplierAddress);
    }
}

// Transaction details module functions
void recordTransaction()
{
    struct Transaction newTransaction;
    printf("Enter transaction ID: ");
    scanf("%d", &newTransaction.transactionId);
    printf("Enter product ID: ");
    scanf("%d", &newTransaction.productId);
    printf("Enter quantity: ");
    scanf("%d", &newTransaction.quantity);
    printf("Enter transaction date: ");
    scanf("%s", newTransaction.transactionDate);
    transactions[transactionCount++] = newTransaction;
    printf("Transaction recorded successfully\n");
}

void updateTransaction()
{
    int transactionId, index = -1;
    printf("Enter transaction ID to update: ");
    scanf("%d", &transactionId);
    for (int i = 0; i < transactionCount; i++)
    {
        if (transactions[i].transactionId == transactionId)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("Enter new product ID: ");
        scanf("%d", &transactions[index].productId);
        printf("Enter new quantity: ");
        scanf("%d", &transactions[index].quantity);
        printf("Enter new transaction date: ");
        scanf("%s", transactions[index].transactionDate);
        printf("Transaction updated successfully\n");
    }
    else
    {
        printf("Transaction not found\n");
    }
}

void displayTransactionHistory()
{
    printf("Transaction History\n");
    printf("ID\tProduct ID\tQuantity\tDate\n");
    for (int i = 0; i < transactionCount; i++)
    {
        printf("%d\t%d\t%d\t%s\n", transactions[i].transactionId, transactions[i].productId, transactions[i].quantity, transactions[i].transactionDate);
    }
}
