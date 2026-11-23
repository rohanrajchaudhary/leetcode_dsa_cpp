class ProductOfNumbers {
    std::vector<int> prefix;
    int count;

public:
    ProductOfNumbers() {
        prefix.reserve(40001);
        prefix.push_back(1);
        count = 0;
    }

    void add(int num) {
        if (num == 0) {
            count = 0;
            return;
        }

        int product = prefix[count] * num;
        count++;

        if (count == prefix.size()) {
            prefix.push_back(product);
        } else {
            prefix[count] = product;
        }
    }

    int getProduct(int k) {
        if (k > count) {
            return 0;
        }

        return prefix[count] / prefix[count - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */