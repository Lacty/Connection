
#include "Audio.hpp"
#include "../Vector/vector.hpp"
#include <iostream>


Audio::Audio() {
  device_ = alcOpenDevice(nullptr);
  context_ = alcCreateContext(device_, nullptr);
  alcMakeContextCurrent(context_);
}

Audio::~Audio() {
  alcMakeContextCurrent(nullptr);
  alcDestroyContext(context_);
  alcCloseDevice(device_);
}


Media::Media(const std::string& _path) :
  source_(_path.c_str())
{
  alGenBuffers(1, &buf_id_);
  alGenSources(1, &src_id_);

  // buf_idにデータを結びつける
  alBufferData(buf_id_,
               source_.isStereo()
               ? AL_FORMAT_STEREO16
               : AL_FORMAT_MONO16,
               source_.data(),
               source_.size(),
               source_.sampleRate());

  // src_idにbuf_idを結びつける
  alSourcei(src_id_, AL_BUFFER, buf_id_);
}

Media::~Media() {
  alDeleteSources(1, &src_id_);
  alDeleteBuffers(1, &buf_id_);
}

Media& Media::play() {
  alSourcePlay(src_id_);
  return *this;
}

Media& Media::stop() {
  alSourceStop(src_id_);
  return *this;
}

Media& Media::pause() {
  alSourcePause(src_id_);
  return *this;
}

Media& Media::setVolume(const float volume) {
  alSourcef(src_id_, AL_GAIN, volume);
  return *this;
}

Media& Media::setPitch(const float pitch) {
  alSourcef(src_id_, AL_PITCH, pitch);
  return *this;
}

Media& Media::setOffset(const float offset) {
  alSourcef(src_id_, AL_SEC_OFFSET, offset);
  return *this;
}

Media& Media::enableLoop() {
  alSourcei(src_id_, AL_LOOPING, true);
  return *this;
}

Media& Media::disableLoop() {
  alSourcei(src_id_, AL_LOOPING, false);
  return *this;
}

const float Media::scale() {
  return source_.time();
}

const float Media::currentTime() {
  ALfloat current_time;
  alGetSourcef(src_id_, AL_SEC_OFFSET, &current_time);
  return current_time;
}

std::vector<float> Media::currentWavData(int sample_num) {
  // 再生位置(秒)を取得
  float t = currentTime();

  // 波形データのどの位置か割り出す
  int offset = int(t * source_.sampleRate());

  // 取り出すサンプル数を決める
  // FIXME:量子化ビット数が16固定
  int sample_max_size = source_.size() / sizeof(short);
  int sample_size = std::min(sample_num, sample_max_size - offset);

  // TIPS:void* 経由で安全に型キャスト
  const void* ptr = source_.data();
  const short* pcm_data = static_cast<const short*>(ptr);

  // short→float
  std::vector<float> samples(sample_num, 0.0f);
  for (int i = 0; i < sample_size; ++i) {
    samples[i] = float(pcm_data[offset + i]) / 200000.0f;
  }

  return std::move(samples);
}