//法1：从前往后遍历
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    stack<int> stk;
    vector<int> res(nums1.size(), -1);


    for(int i=0; i<nums2.size(); i++){
        int num = nums2[i];
        while(!stk.empty() && num > stk.top()){
            map[stk.top()] = num;
            stk.pop();
        }
        map[num] = -1;
        stk.push(num);
    }

    for(int i=0; i<nums1.size(); i++){
        res[i] = map[nums1[i]];
    }
    return res;
}


//法2：从后往前遍历
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    stack<int> stk;
    
    for(int i=nums2.size()-1; i>=0; i--){
        int num = nums2[i];
        while(!stk.empty() && num > stk.top()){
            stk.pop();
        }
        map[num] = stk.empty() ? -1 : stk.top();
        stk.push(num);
    }

    vector<int> res;
    for(int i=0; i<nums1.size(); i++){
        res.push_back(map[nums1[i]]);
    }
    return res;
}



