#include <vector>

std::vector<int> find_elements_indexes(std::vector<int> arr, int sum)
{
    std::unordered_map<int, std::pair<int, int>> map;
    std::vector<int> result;
    int size = arr.size();

    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            map[arr[i] + arr[j]] = std::make_pair(i, j);
        }
    }
    for (auto item1 = map.begin(); item1 != map.end(); item1++) {
        int sum1 = item1->first;
        int i = item1->second.first;
        int j = item1->second.second;

        for (auto item2 = map.begin(); item2 != map.end(); item2++) {
            int sum2 = item2->first;
            int k = item2->second.first;
            int l = item2->second.second;

            if (i != k && i != l && j != k && j != l && sum1 + sum2 == sum) {
                result.push_back(i);
                result.push_back(j);
                result.push_back(k);
                result.push_back(l);
                return result;
            }
        }
    }
    return result;
}