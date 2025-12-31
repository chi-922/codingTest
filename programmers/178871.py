// 달리기 경주

def solution(players, callings):
    answer = ['' for _ in range(len(players))]
    horses = dict()
    rank = dict()
    
    for i in range(1, len(players) + 1):
        horses[players[i - 1]] = i
        rank[i] = players[i - 1]
    
    for call in callings:
        # 추월하기 전 등수
        num = horses[call]
        # 추월당한 말
        other_horse = rank[num - 1]
        
        # 추월 후
        horses[call] -= 1
        horses[other_horse] += 1
        rank[num - 1] = call
        rank[num] = other_horse
    
    for horse in horses:
        answer[horses[horse] - 1] = horse
    
    return answer
