// refrenced "Solution in C++" by ashish_madhup

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

    // set to store deadends
    unordered_set<string> deadendSet(deadends.begin(), deadends.end());

    // check if first is a deadend
    if (deadendSet.count("0000")){
        return -1;
    }
        
    // queue for BFS traversal
    queue<string> q;
    q.push("0000");

    // set to keep track of seen 
    unordered_set<string> seen;
    seen.insert("0000");

    // answer we are looking for
    int turns = 0;

    // does BFS
    while (q.empty() == false) {
        int levelSize = q.size();
        
        // look through current level
        for (int i = 0; i < levelSize; i++) {
            string current = q.front();
            q.pop();

            // check if we reached the target
            if (current == target){
                return turns;
            }

            // look at all moves from the current 
            for (int j = 0; j < 4; j++) {
                string next = current;

                // clockwise rotation
                next[j] = (next[j] - '0' + 1) % 10 + '0';
               if (seen.find(next) == seen.end() && deadendSet.find(next) == deadendSet.end()) {
                    seen.insert(next);
                    q.push(next);
                }

                // counter-clockwise rotation
                next[j] = (next[j] - '0' + 8) % 10 + '0';
                if (seen.find(next) == seen.end() && deadendSet.find(next) == deadendSet.end()) {
                    seen.insert(next);
                    q.push(next);
                }
            }
        }

        turns++;
    }

    // cant reach the target
    return -1;
    }
};
