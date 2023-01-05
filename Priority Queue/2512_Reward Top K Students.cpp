class Solution {
public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& r, vector<int>& id, int k) {
        auto comp = [](pair<int, int> &a, pair<int, int> &b){
          if(a.first == b.first) return a.second > b.second;
          return a.first < b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        map<string,int> m;
        for(auto i:pf){
            m[i]=1;
        }
        for(auto i:nf){
            m[i]=-1;
        }
        int n=r.size();
        vector<int> ans;
        vector<pair<int,int>> kk;

        for(int i=0;i<n;i++){
            vector<string> t;
            string s="";
            for(auto ch:r[i]){
                if(ch==' '){
                    t.push_back(s);
                    s="";
                }
                else{
                    s+=ch;
                }
            }
            t.push_back(s);

            int run=0;

            for(auto x:t){
                if(m[x]==1){
                    run+=3;
                }
                else if(m[x]==-1){
                    run--;
                }
            }
            //kk.push_back({run,id[i]});
            pq.push({run,id[i]});
        }
        
        // sort(kk.rbegin(),kk.rend());

        // for(auto i:kk){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
