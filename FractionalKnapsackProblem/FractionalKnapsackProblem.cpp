
#include <iostream>
#include <algorithm>
#include <vector>

struct Object {
    int id;
    int weight;
    double value;
    double value_per_unit_weight;

    Object(int i, int w, double v) : id(i), weight(w), value(v), value_per_unit_weight(v / w) {}

    inline bool operator<(const Object& obj) const
    {
        return this->value_per_unit_weight < obj.value_per_unit_weight;
    }

    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

std::ostream& operator<<(std::ostream& os, const Object& obj)
{
    os << "[" << obj.id << "] 가격 : " << obj.value
        << " \t 무게 : " << obj.weight
        << " kg \t 단위 무게 당 가격 : " << obj.value_per_unit_weight;
    return os;
}

auto fill_knapsack(std::vector<Object>& objects, int knapsack_capacity)
{
    std::vector<Object> knapsack_contents;
    knapsack_contents.reserve(objects.size());

    std::sort(objects.begin(), objects.end());
    std::reverse(objects.begin(), objects.end());
    //내림차순 정렬 -> 
    //단위 무게당 가장 가치있는 것들부터 가방에 들어감

    auto current_object = objects.begin();
    int current_total_weight = 0;
    while (current_total_weight < knapsack_capacity && current_object != objects.end())
    {
        knapsack_contents.push_back(*current_object); //
        
        current_total_weight += current_object->weight;
        current_object++;
    }

    int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
    Object& last_object = knapsack_contents.back();
    if (weight_of_last_obj_to_remove > 0)
    {
        last_object.weight -= weight_of_last_obj_to_remove;
        last_object.value -= last_object.value_per_unit_weight * weight_of_last_obj_to_remove;
    }

    return knapsack_contents;

}


int main()
{
    std::cout << "Hello World!\n";
}
