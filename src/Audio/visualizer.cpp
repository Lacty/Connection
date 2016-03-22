
#include "visualizer.hpp"
#include "audio.hpp"
#include "../Graphic/graphic.hpp"


Visualizer::Visualizer(Media* media) :
  media_(media), height_lower_(1) {
  assert(media_ != nullptr);
}

Visualizer::Visualizer(Media* media, const Vec2f& pos, const Vec2f& size, int split_num) :
  media_(media),
  pos_(pos),
  size_(size),
  split_num_(split_num),
  width_(size.x / split_num),
  height_upper_(size.y),
  height_lower_(1) {
  assert(media_ != nullptr);
}


void Visualizer::draw() {
  std::vector<float> samples = media_->currentWavData(1024);
  
  // ���o�����g�`��܂���O���t�ŕ`��
  for (size_t i = 1; i < samples.size(); ++i) {
    float x1 = (float(size_.x) / samples.size()) * (i - 1) - (size_.x  / 2);
    float x2 = (float(size_.x) / samples.size()) * i - (size_.x / 2);

    float y1 = float(size_.y / 2) * samples[i - 1];
    float y2 = float(size_.y / 2) * samples[i];

    drawLine(Vec2f(x1, y1), Vec2f(x2, y2), 2, Color(1, 0, 0));
  }
}

void Visualizer::drawWithFFT() {
  std::vector<float> samples = media_->currentWavData(1024 * 10);

  // FFT���s
  Eigen::FFT<float> fft;
  std::vector<std::complex<float> > freq;
  fft.fwd(freq, samples);

  // FFT��͌��ʂ�܂���O���t�ŕ\��
  //  ���E�Ώ̂Ȍ��ʂ�������̂ŁA���������\�����Ă���
  size_t freq_size = freq.size() / 40;
  for (size_t i = 1; i < freq_size; ++i) {
    float x1 = (float(size_.x) / freq_size) * (i - 1) - (size_.x / 2);
    float x2 = (float(size_.x) / freq_size) * i - (size_.x / 2);

    std::complex<float> a = freq[i - 1];
    std::complex<float> b = freq[i];

    float y1 = std::sqrt(a.real() * a.real() + a.imag() * a.imag()) - (size_.y / 2);
    float y2 = std::sqrt(b.real() * b.real() + b.imag() * b.imag()) - (size_.y / 2);

    drawLine(pos_ + Vec2f(x1, y1), pos_ + Vec2f(x2, y2), 2, Color(0, 0, 1));
  }
}

Visualizer& Visualizer::setPos(const Vec2f& pos) {
  pos_ = pos;
  return *this;
}
Visualizer& Visualizer::setSize(const Vec2f& size) {
  size_ = size;
  return *this;
}
Visualizer& Visualizer::setLineWidth(const float width) {
  width_ = width;
  return *this;
}
Visualizer& Visualizer::setSplitNum(const int num) {
  split_num_ = num;
  return *this;
}
Visualizer& Visualizer::setHeightUpper(const float limit) {
  height_upper_ = limit;
  return *this;
}
Visualizer& Visualizer::setHeightLower(const float limit) {
  height_lower_ = limit;
  return *this;
}