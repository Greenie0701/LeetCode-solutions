class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0){
                result.push_back(asteroids[i]);
            }else{
                // Pop all asteroids which are lesser than current asteroid
                while(!result.empty()&&result.back()>0&&result.back()<abs(asteroids[i])){
                    result.pop_back();
                }
                // Check if the size of asteroids are equal
                if(!result.empty()&&result.back()==abs(asteroids[i])){
                    result.pop_back();
                }
                // Push the asteroid to the array if it is neg/stack is empty
                else if(result.empty()||result.back()<0){
                    result.push_back(asteroids[i]);
                }
            }
        }
        return result;
    }
};