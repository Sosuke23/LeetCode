class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>idx; //storing the index
        for(int i=0;i<s1.size();i++){
                //if the values are not equal then store its index.
            if(s1[i]!=s2[i]){ 
                idx.push_back(i);
            }
            // if we have found more than 2 index where value does not match, 
            // then break.
            if (idx.size()>=2) break; 
        }
        // if size==1, then we cannot swap, as swapping needs 2 values.
        if(idx.size()==1)return false;
        // if size of idx is zero then strings are already equal
        else if(idx.size()==0) return true; 
        else {
            swap(s2[idx[0]],s2[idx[1]]); //swaping the indexes that we have found.
            return s1==s2; //if after swap both the string are same.
        }
    }
};