// Last updated: 24/11/2026, 01:33:49
1class ProductOfNumbers {
2private:
3    // Stores cumulative product of the stream
4    vector<int> prefixProduct;
5    int size = 0;
6
7public:
8    ProductOfNumbers() {
9        // Initialize the product list with 1 to handle multiplication logic
10        prefixProduct.push_back(1);
11        size = 0;
12    }
13
14    void add(int num) {
15        if (num == 0) {
16            // If num is 0, reset the cumulative products since multiplication
17            // with 0 invalidates previous products
18            prefixProduct = {1};
19            size = 0;
20        } else {
21            // Append the cumulative product of the current number with the last
22            // product
23            prefixProduct.push_back(prefixProduct[size] * num);
24            size++;
25        }
26    }
27
28    int getProduct(int k) {
29        // Check if the requested product length exceeds the size of the valid
30        // product list
31        if (k > size) return 0;
32
33        // Compute the product of the last k elements using division
34        return prefixProduct[size] / prefixProduct[size - k];
35    }
36};