#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first) {
            // 수록곡 재생횟수 같을 때
            return a.second > b.second;  // 고유번호 오름차순
        }
        return a.first < b.first;  // 평소엔 노래 내림차순
    }
};


vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> numGenre;
    vector<pair<int, int>> seqGenre(100);  // i번 장르는 몇번 재생됐나
    int num = 0;   // 장르 갯수
    for (int i = 0; i < genres.size(); i++)
    {
        if (numGenre.find(genres[i]) != numGenre.end())
        {
            // 있는 경우
            seqGenre[numGenre[genres[i]]].first += plays[i];
            seqGenre[numGenre[genres[i]]].second++;
        }
        else {
            numGenre[genres[i]] = num;
            seqGenre[num].first += plays[i];
            seqGenre[num].second = 1;
            num++;
        }
    }

    // 장르 내림차순
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < num; i++)
    {
        pq.push({ seqGenre[i].first, i });  // 장르 수록곡 몇번 재생됐는지, num장르 번호
    }

    vector<pair<int, int>> idx(num);
    int pidx = 0;

    while (!pq.empty())
    {
        int seq = pq.top().first, numG = pq.top().second;
        pq.pop();
        idx[numG].first = pidx;
        idx[numG].second = 0;  // 진짜 실릴 수록곡은 2개까지
        // 장르에 수록곡 2개 초과인지
        if (seqGenre[numG].second >= 2) pidx += 2;
        else pidx += 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> seqPq;
    for (int i = 0; i < plays.size(); i++)
    {
        seqPq.push({ plays[i], i });   // 수록곡 재생 횟수, 고유번호
    }

    vector<int> answer(pidx, 0);
    while (!seqPq.empty())
    {
        int goyou = seqPq.top().second;
        int numG = numGenre[genres[goyou]];
        seqPq.pop();
        if (idx[numG].second < 2)
        {
            answer[idx[numG].first] = goyou;
            idx[numG].first++;
            idx[numG].second++;
        }
    }

    return answer;
}
