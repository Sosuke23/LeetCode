class Solution {
private:
    long long evaluate(string& exp, int& idx) {
        // handle the number case
        if (isdigit(exp[idx]) || exp[idx] == '-') {
            long long rst = 0;
            long long neg = 1;
            if (exp[idx] == '-') {
                idx += 1;
                neg = -1;
            }
            
            while (idx < exp.length() && isdigit(exp[idx])) {
                rst = rst * 10 + exp[idx] - '0';
                idx += 1;
            }
            return neg * rst;
        }
        
        string op = exp.substr(idx, 3);
        idx += 4; // skip op and the (
        
        long long a = evaluate(exp, idx);
        idx += 1; // skip the ","
        long long b = evaluate(exp, idx);
        idx += 1; // skip the )
        
        if (op == "add") {
            return a + b;
        }
        if (op == "sub") {
            return a - b;
        }
        if (op == "mul") {
            return a * b;
        }
        if (op == "div") {
            return a / b;
        }
        return 0;
    }
public:
    long long evaluateExpression(string expression) {
        int idx = 0;
        return evaluate(expression, idx);
    }
};