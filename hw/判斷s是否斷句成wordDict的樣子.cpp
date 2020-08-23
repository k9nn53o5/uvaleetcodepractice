class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0){return false;}
        vector<string> subStrs;
        subStrs.insert(subStrs.begin(),s);
        for(int i=0;i<subStrs.size();i++){ 
            cout<<subStrs[i]<<endl;
        }
        for(auto word : wordDict){
            for(auto sub : subStrs){
                if(sub.find(word) != -1){
                    int foundfir=sub.find(word);
                    int foundlast=foundfir+word.size()-1;
                    vector <string>::iterator it = subStrs.end();
                    if(foundfir!=0){
                        it = subStrs.insert( it, sub.substr(0 , foundfir-1) ) ;
                    }
                    it = subStrs.end();
                    if(foundlast!=sub.size()-1){
                        it = subStrs.insert( it,sub.substr(foundlast+1,sub.size()-1) );
                    }
                    subStrs.erase(find(subStrs.begin(),subStrs.end(),sub));
                    
                    for(int i=0;i<subStrs.size();i++){
                        cout<<subStrs[i]<<" ";
                    }
                    
                    cout<<endl;
                }
                else{
                    return false;
                }
            }
        }
    return true;
    }
};
