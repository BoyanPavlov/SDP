#include <iostream>
#include <array>
#include <queue>

class minMoves
{
private:
    using position = std::pair<int, int>;
    using positionAndSteps = std::pair<position, int>;

    unsigned int boardSize = 8;
    bool **playground = nullptr;

    void allocatePlayground(unsigned int boardSize)
    {
        playground = new bool *[boardSize];
        for (size_t i = 0; i < boardSize; i++)
        {
            playground[i] = new bool[boardSize];
        }
    }


    void freePlayground()
    {
        for (size_t i = 0; i < boardSize; i++)
        {
            delete[] playground[i];
        }
        delete[] playground;
    }

    void cleanPlayground()
    {
        for (size_t i = 0; i < boardSize; i++)
        {
            for (size_t j = 0; j < boardSize; j++)
            {
                playground[i][j] = false;
            }
        }
    }

    bool equalPositions(const position &fst, const position &snd)
    {
        return (fst.first == snd.first && fst.second == snd.second);
    }

    bool isValidPos(const position &p)
    {
        return p.first >= 0 && p.second >= 0 && p.first < boardSize && p.second < boardSize;
    }

    void mark(const position &toMark)
    {
        playground[toMark.first][toMark.second] = true;
    }

    bool isMarked(const position &pos) const
    {
        return playground[pos.first][pos.second];
    }

    void pushAndMark(std::queue<positionAndSteps> &q, const position &toPush, int steps)
    {
        if (isValidPos(toPush) && !isMarked(toPush))
        {
            q.push({toPush, steps});
            mark(toPush);
        }
    }

    int process(const position &startPos, const position &endPos)
    {
        std::queue<positionAndSteps> q;
        q.push({startPos, 0});

        while (!q.empty())
        {
            positionAndSteps currentPosition = q.front();
            q.pop();

            if (equalPositions(currentPosition.first, endPos))
            {
                return currentPosition.second;
            }

            int x = currentPosition.first.first;
            int y = currentPosition.first.second;
            int moves = currentPosition.second + 1;

            pushAndMark(q, {x + 1, y + 2}, moves);
            pushAndMark(q, {x + 1, y - 2}, moves);
            pushAndMark(q, {x - 1, y + 2}, moves);
            pushAndMark(q, {x - 1, y - 2}, moves);

            pushAndMark(q, {x + 2, y + 1}, moves);
            pushAndMark(q, {x + 2, y - 1}, moves);
            pushAndMark(q, {x - 2, y + 1}, moves);
            pushAndMark(q, {x - 2, y - 1}, moves);
        }
        return -1;
    }

public:
    minMoves()
        : boardSize(6)
    {
        allocatePlayground(boardSize);
        cleanPlayground();
    }
    minMoves(int size)
        : boardSize(size)
    {
        allocatePlayground(boardSize);
        cleanPlayground();
    }

    int getMinMoves(const position &start, const position &end)
    {
        cleanPlayground();
        return process(start, end);
    }

    ~minMoves()
    {
        freePlayground();
    }
};

int main()
{
    minMoves m;
    std::cout << m.getMinMoves({0, 0}, {5, 3}) << std::endl;

    minMoves t(12);
    std::cout << t.getMinMoves({0, 0}, {11, 11}) << std::endl;

    minMoves c(2);
    std::cout << c.getMinMoves({0, 0}, {12, 212});

    return 0;
}
