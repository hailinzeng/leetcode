class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> indexs;
        
        if(numbers.size() < 2){
            return indexs;
        }
        
        // build map: number -> index vector
        map<int, vector<int>*> num2idx;
        
        for(int i = 0; i < numbers.size(); i++){
            int num2idxkey = numbers[i];
            vector<int>* num2idxval;
            
            map<int, vector<int>*>::iterator fit = num2idx.find(num2idxkey);
            
            if(fit == num2idx.end()){
                num2idxval = new vector<int>();
                
                num2idx.insert(pair<int, vector<int>*>(num2idxkey, num2idxval));
            }else{
                num2idxval = fit->second;
            }
            
            num2idxval->push_back(i);
        }
        
        // case 1: number1 == number2
        bool found = false;
        
        if(target % 2 == 0){
            map<int, vector<int>*>::iterator fit = num2idx.find(target/2);
            if(fit != num2idx.end()){
                vector<int>* num2idxval = fit->second;
                if(num2idxval->size() > 1){
                    indexs.push_back(num2idxval->at(0) + 1);
                    indexs.push_back(num2idxval->at(1) + 1);
                    found = true;
                }
            }
        }
        
        // case 2: number1 != number2
        if(!found){
            for(map<int, vector<int>*>::iterator it = num2idx.begin(); it != num2idx.end(); it++){
                int number1 = it->first;

                if(number1 > target / 2){
                    break;
                }
                
                map<int, vector<int>*>::iterator jt = num2idx.find(target - number1);
                if(jt != num2idx.end()){
                    if(it->second->at(0) < jt->second->at(0)){
                        indexs.push_back(it->second->at(0) + 1);
                        indexs.push_back(jt->second->at(0) + 1);
                    }else{
                        indexs.push_back(jt->second->at(0) + 1);
                        indexs.push_back(it->second->at(0) + 1);
                    }
                    break;
                }
            }
        }
        
        // clean 
        while(!num2idx.empty()){
            map<int, vector<int>*>::iterator it = num2idx.begin();
            
            vector<int>* num2idxval = it->second;
            delete num2idxval;
            
            num2idx.erase(it);
        }
        
        return indexs;
    }
};
