class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
                vector<int>ans;
                int index = 0;
                while ((index = txt.find(pat, index)) != std::string::npos) {
                    ans.push_back(index+1);
                    index += 1;
                }
                return ans;
        }
     
};
