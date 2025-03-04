class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> s;
        for (auto ch : e) {
            if (ch == ')') {
                auto hasT = false, hasF = false;
                while (s.top() == 't' || s.top() == 'f') {
                    hasT |= s.top() == 't';
                    hasF |= s.top() == 'f';
                    s.pop();
                }
                auto op = s.top();
                s.pop();
                s.push(op == '!'   ? hasF ? 't' : 'f'
                       : op == '&' ? !hasF ? 't' : 'f'
                       : hasT      ? 't'
                                   : 'f');
            } else if (ch != ',' && ch != '(')
                s.push(ch);
        }
        return s.top() == 't' ? true : false;
    }
};