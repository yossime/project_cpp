#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Cat
{
private:
   float m_weight;

public:
   Cat(float weight) : m_weight(weight){};
   ~Cat() = default;

   float getWeight() const { return m_weight; };
   bool operator>(const Cat &r) const
   {
      return m_weight > r.getWeight();
   }
};

// bool Cat::operator>(const Cat,const Cat)

void sortcat(std::vector<std::shared_ptr<Cat>> &cats)
{
   std::sort(cats.begin(), cats.end(), [](const std::shared_ptr<Cat> r1, const std::shared_ptr<Cat> &r2) -> bool
             { return r1.get()->getWeight() < r2.get()->getWeight(); });
};

void printvec(std::vector<std::shared_ptr<Cat>> &cats)
{
   for (auto it = cats.begin(); it != cats.end(); ++it)
      std::cout << ' ' << it->get()->getWeight() << std::endl;
   std::cout << '\n';
}

int main()
{
   std::vector<std::shared_ptr<Cat>> cats;

   std::shared_ptr<Cat> cat1 = std::make_shared<Cat>(2);
   std::shared_ptr<Cat> cat2 = std::make_shared<Cat>(4);
   std::shared_ptr<Cat> cat3 = std::make_shared<Cat>(1);
   std::shared_ptr<Cat> cat4 = std::make_shared<Cat>(3);

   cats.push_back(cat1);
   cats.push_back(cat2);
   cats.push_back(cat3);
   cats.push_back(cat4);

   printvec(cats);
   sortcat(cats);
   printvec(cats);
}