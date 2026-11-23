class ProductOfNumbers {
public:
    vector<long long> prd;
    ProductOfNumbers() {
        prd = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            prd = {1};
        }
        else {
            prd.push_back(num * prd.back());
        }
    }
    
    int getProduct(int k) {
        int n = (int)prd.size();
        int idx = n - k - 1;
        if (idx < 0) {
            return 0;
        }
        int res = prd.back() / prd[idx];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */