
#include "utility.hpp"


double toRadians(float deg) {
  return (deg * M_PI) / 180.0f;
}

Vec3f nearPosOnLine(const Vec3f& p,
                    const Vec3f& vA,
                    const Vec3f& vB)
{
  Vec3f AB, AP;
  AB = vB - vA;
  AP = p - vA;

  AB.normalize();

  float distAX = AB.dot(AP);

  Vec3f ret;
  ret = vA + (AB * distAX);

  return ret;
}