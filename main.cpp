#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

class World{
public:
    int rows, cols;
    vector<string> data;

    World(istream &in){
        string line;
        // Read rows and cols
        in >> rows >> cols;
        // Throw away remaining \n
        getline(in, line);

        for(int r = 0; r < rows; r++){
            // Read the line
            getline(in, line);
            data.push_back(line);

            // Check for the start
            auto tmp = line.find('1');
            if(tmp != line.npos){
                start.first  = r;
                start.second = tmp;
            }
            // Check for the goal
            tmp = line.find('0');
            if(tmp != line.npos){
                goal.first  = r;
                goal.second = tmp;
            }
        }
    }

    void print(){
        for(const string &line : data){
            cout << line << endl;
        }
    }
    
    // This reads in the world and creates a vector of strings.
    // Imagine that a string is just a vector of characters.
    // You can still go data[r][c] 
    // You do not have to use this code.
    //
    // Remember that the C++ stack from the standard library doesn't
    //  return the value when popping, so you need to look at the top
    //  value first.
    // http://www.cplusplus.com/reference/stack/stack/
};

int main()
{
    //fstream f("maze4.txt");
    //World w(f);
    World w(cin);
    w.DFS();
    return 0;
}

