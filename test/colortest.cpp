#include "rang.hpp"

int main() {

  //Visual test for background colors
  std::cout<<rang::bg::green<<"This has a green background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::red<<"This has a red background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::black<<"This has a black background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::yellow<<"This has a yellow background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::blue<<"This has a blue background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::magenta<<"This has a magenta background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::cyan<<"This has a cyan background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bg::gray<<rang::fg::black<<"This has a gray background"<<rang::style::reset<<std::endl;

  std::cout<<std::endl;

  //Visual test for foreground colors
  std::cout<<rang::fg::green<<"This has a green colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::red<<"This has a red colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::black<<"This has a black colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::yellow<<"This has a yellow colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::blue<<"This has a blue colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::magenta<<"This has a magenta colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::cyan<<"This has a cyan colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fg::gray<<"This has a gray colored text"<<rang::style::reset<<std::endl;

  std::cout<<std::endl;

  //Visual test for bright background colors
  std::cout<<rang::bgB::green<<"This has a bright green background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::red<<"This has a bright red background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::black<<"This has a bright black background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::yellow<<rang::fg::black<<"This has a bright yellow background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::blue<<"This has a bright blue background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::magenta<<"This has a bright magenta background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::cyan<<"This has a bright cyan background"<<rang::style::reset<<std::endl;
  std::cout<<rang::bgB::gray<<rang::fg::black<<"This has a bright gray background"<<rang::style::reset<<std::endl;

  std::cout<<std::endl;

  //Visual test for bright foreground colors
  std::cout<<rang::fgB::green<<"This has a bright green colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::red<<"This has a bright red colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::black<<"This has a bright black colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::yellow<<"This has a bright yellow colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::blue<<"This has a bright blue colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::magenta<<"This has a bright magenta colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::cyan<<"This has a bright cyan colored text"<<rang::style::reset<<std::endl;
  std::cout<<rang::fgB::gray<<"This has a bright gray colored text"<<rang::style::reset<<std::endl;

  std::cout<<std::endl;

  //Visual test for text effects
  std::cout<<rang::style::reset<<"This is the default text"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::bold<<"This text is bold"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::dim<<"This text is dim"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::italic<<"This text is italic"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::underline<<"This text is underlined"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::blink<<"This text has a blink effect"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::reversed<<"This text is reversed"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::conceal<<"This text is concealed"<<rang::style::reset<<std::endl;
  std::cout<<rang::style::crossed<<rang::fg::black<<"This text is crossed"<<rang::style::reset<<std::endl;
  return 0;
}