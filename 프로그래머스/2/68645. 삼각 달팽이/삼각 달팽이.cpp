#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int totalLen = 0;
int DiectionIndex = 0;

struct Pos
{
    int col;
    int row;
    
    Pos (int col, int row) : col(col), row(row) {}
    
    Pos operator+(const Pos& Other) const
    {
        return Pos(col + Other.col, row + Other.row);
    }
};

Pos Directions[3] =
{
    Pos(0, 1),
    Pos(1, 0),
    Pos(-1, -1)
};


int GetIndexByPos(const Pos& pos)
{
    int ret = 0;
    
    ret = pos.row * (pos.row + 1) / 2;
    ret += pos.col;
    
    return ret;
}

bool IsValidIndex(int index)
{
    if (index < 0 || index >= totalLen)
        return false;
    
    if (answer[index] != 0)
        return false;
    
    return true;
}

void MoveNextPos(Pos& CurrentPos)
{
    Pos NextPos = CurrentPos + Directions[DiectionIndex];
    int index = GetIndexByPos(NextPos);
    
    if (IsValidIndex(index) == false)
    {
        DiectionIndex = (DiectionIndex + 1) % 3;
        NextPos = CurrentPos + Directions[DiectionIndex];
    }
    
    CurrentPos = NextPos;
}

vector<int> solution(int n) {
    totalLen = n * (n + 1) / 2;
    
    answer.resize(totalLen, 0);
    
    Pos currentPos = Pos(0,0);
    for (int i = 1; i <= totalLen; i++)
    {
        int curretnIndex = GetIndexByPos(currentPos);
        
        answer[curretnIndex] = i;
        
        MoveNextPos(currentPos);
    }

    return answer;
}