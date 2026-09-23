#include <iostream>
#include <memory>

class BaseClass {
  private:
    std::string private_str_;

  protected:
    std::string protected_str_;

  public:
    std::string public_str_;

    BaseClass(std::string private_str, std::string protected_str, std::string public_str) {
        private_str_ = private_str;
        protected_str_ = protected_str;
        public_str_ = public_str;
    }

    std::string get_private_str() { return private_str_; }
};

class ChildClass : public BaseClass {

  public:
    ChildClass(std::string private_str, std::string protected_str, std::string public_str) : BaseClass(private_str, protected_str, public_str) {}
    std::string get_protected_str() { return protected_str_; }
};

int main() {
    auto child_class = std::make_unique<ChildClass>("private string", "protected string", "public string");

    std::cout << child_class->get_private_str() << std::endl;
    std::cout << child_class->get_protected_str() << std::endl;
    std::cout << child_class->public_str_ << std::endl;

    return 0;
}