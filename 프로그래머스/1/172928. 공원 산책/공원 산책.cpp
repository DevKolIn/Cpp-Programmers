#include <string>
#include <vector>
#include <map>

using namespace std;

struct Pos
{
    Pos(int y, int x) : y(y), x(x) {}
    int y;
    int x;
};

vector<int> FindStartPostion(const vector<string>& Map)
{
    vector<int> StartPos(2, 0);
    
    for (int y = 0; y < Map.size(); y++)
    {
        for (int x = 0; x < Map[0].size(); x++)
        {
            if (Map[y][x] == 'S')
            {
                StartPos[0] = y;
                StartPos[1] = x;
                return StartPos;
            }
        }
    }
    
    return StartPos;
}

bool CanMove(const vector<string>& Map, int MoveY, int MoveX)
{
    int MapHeight = Map.size();
    int MapWidth = Map[0].size();
    
    if (MoveY >= MapHeight || MoveY < 0)
        return false;
    if (MoveX >= MapWidth || MoveX < 0)
        return false;
    if (Map[MoveY][MoveX] == 'X')
        return false;
    
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = FindStartPostion(park); 
    
    Pos front[4] =
    {
        Pos(0, -1), // West
        Pos(0, 1), // East
        Pos(1, 0), // South
        Pos(-1, 0), // North
    };
    
    map<char, int> DirMap = {
        {'W', 0},
        {'E', 1},
        {'S', 2},
        {'N', 3},
    };
    
    for (string& route : routes)
    {
        char Direction = route[0];
        int WalkCount = route[2] - '0';

        int CurY = answer[0];
        int CurX = answer[1];

        while (WalkCount--)
        {
            Pos MovePos = front[DirMap[Direction]];
            CurY += MovePos.y;
            CurX += MovePos.x;
            
            if (CanMove(park, CurY, CurX) == false)
            {
                break;
            }
        }
        
        if (WalkCount < 0)
        {
            answer[0] = CurY;
            answer[1] = CurX;
        }
    }
    
    return answer;
}