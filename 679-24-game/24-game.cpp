class Solution {
public:
vector<double>fill(double a,double b){
// all operations
  vector<double>v={a+b,a-b,b-a,a*b};
    if(a!=0) v.push_back(b/a);
    if(b!=0) v.push_back(a/b);
  
  return v;
}
bool check(vector<double>&newl){
  if(newl.size()==1){
 // We have only one number left, check if it is approximately 24.
// will have only one element after appling operations    
return abs(newl[0]-24)<=0.1;
// <=0.1 is for upto 1 decimal places for approximation
  }
  for(int i=0;i<newl.size();i++){
    for(int j=i+1;j<newl.size();j++){
            vector<double> newList;
                for (int k = 0; k < newl.size(); k++) {
// pushing every element except i , j as we pus operation result of i,j
                    if (k != j && k != i) {
                        newList.push_back(newl[k]);
                    }
                }
                
    
   vector<double>res;
// new vector to store all possible obtained result
     res=fill(newl[i],newl[j]);
           for(int l=0;l<res.size();l++){
// push one operation
             newList.push_back(res[l]);
// check if the array is meeting requirement
             if(check(newList)) return true;
// if not pop last push
               newList.pop_back();
         }
  }}
  return false;
}
    bool judgePoint24(vector<int>& cards) {
        vector<double> newl(cards.begin(), cards.end());
        return check(newl);
    }
};