class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //Map to count the frequency of the elements in the nums1 vector
        unordered_map<int,int> map;
        //Vector that stores the intersection of the arrays 
        vector<int> res;
        //Calculate the size of both the vectors
        int n=nums1.size();
        int m=nums2.size();
        //Store the frequecny of each element in vector nums1
        for(int i=0;i<n;i++)
        {
            map[nums1[i]]++;
        }
        //Traverse the vector nums2 and checking if the number exists in the hashmap
        for(int i=0;i<m;i++)
        {
            if(map[nums2[i]]>0)//To check if the element exists in the map
            {
                res.push_back(nums2[i]);//Inserts the element in the result vector
                map[nums2[i]]--;//Decrement the frequency 
            }
        }
        return res;//Returns the array of intersection 
    }
};