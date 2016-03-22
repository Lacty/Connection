
#ifndef overhauserHPP
#define overhauserHPP

#include "../Vector/vector.hpp"
#include <vector>


class CRSpline
{
public:

  // Constructors and destructor
  CRSpline();
  CRSpline(const CRSpline&);
  ~CRSpline();

  // Operations
  void AddSplinePoint(const Vec3f& v);
  Vec3f GetInterpolatedSplinePoint(float t);   // t = 0...1; 0=vp[0] ... 1=vp[max]
  int GetNumPoints();
  Vec3f& GetNthPoint(int n);

  // オプションで追加
  // データの削除
  void Clear();

  // Static method for computing the Catmull-Rom parametric equation
  // given a time (t) and a vector quadruple (p1,p2,p3,p4).
  static Vec3f Eq(float t, const Vec3f& p1, const Vec3f& p2, const Vec3f& p3, const Vec3f& p4);

private:
  std::vector<Vec3f> vp;
  float delta_t;
};

#endif
