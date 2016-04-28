
#pragma once
#include <memory>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include "wav.hpp"


class Audio {
private:
  ALCdevice*  device_;
  ALCcontext* context_;

public:
  Audio();
  ~Audio();

  Audio(const Audio& src) = delete;
  Audio& operator=(const Audio& src) = delete;
};

class Media {
private:
  Wav source_;

  ALuint buf_id_;
  ALuint src_id_;

public:
  explicit Media(const std::string& path);
  ~Media();

  Media(const Media& src) = delete;
  Media& operator=(const Audio& src) = delete;

  Media& play();
  Media& stop();
  Media& pause();
  Media& setVolume(const float volume);
  Media& setPitch(const float pitch);
  Media& setOffset(const float offset);
  Media& enableLoop();
  Media& disableLoop();

  const float scale();
  const float currentTime();

  // 現在の再生場所から指定した範囲のサンプルを取り出す
  std::vector<float> currentWavData(int sample_num);
};