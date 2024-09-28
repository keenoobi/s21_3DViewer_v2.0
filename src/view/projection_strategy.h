#ifndef PROJECTION_STRATEGY_H
#define PROJECTION_STRATEGY_H

namespace s21 {

class ProjectionStrategy {
 public:
  virtual ~ProjectionStrategy() = default;
  virtual void ApplyProjection(QMatrix4x4& projectionMatrix) = 0;
};

class PerspectiveProjection : public ProjectionStrategy {
 public:
  void ApplyProjection(QMatrix4x4& projectionMatrix) override {
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  }
};

class OrthographicProjection : public ProjectionStrategy {
 public:
  void ApplyProjection(QMatrix4x4& projectionMatrix) override {
    projectionMatrix.setToIdentity();
    projectionMatrix.ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
  }
};
}  // namespace s21

#endif  // PROJECTION_STRATEGY_H
