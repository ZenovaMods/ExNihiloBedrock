#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

class Matrix {
public:
    static const Matrix IDENTITY;
protected:
    glm::mat4x4 _m;

public:
    static Matrix makePerspectiveRadians(float, float, float, float);
    static Matrix makeOrtho(float, float, float, float, float, float);

    Matrix() = default;

    Matrix(const glm::quat& q) {
        
    }

protected:
    Matrix(const glm::mat4x4&);
public:
    operator glm::mat4 const& () const;

    void transform3(glm::vec3&, float&) const {

    }

    void transform3(glm::vec3&) const {

    }

    void rotate3(glm::vec3& v) const {

    }

    void translate(float x, float y, float z) {
        _m[3] += (_m[0] * x) + (_m[1] * y) + (_m[2] * z);
    }

    void translate(const glm::vec3& t) {
        translate(t.x, t.y, t.z);
    }

    void setTranslate(float, float, float);
    void setTranslate(const glm::vec3&);

    void setRow(int, float, float, float, float) {

    }

    void setRow(int, const glm::vec3&, float);
    void getRow(int, glm::vec3&, float&) const;

    float get(int row, int col) const {
        return _m[row][col];
    }

    glm::vec3 getTranslation() const;

    void rotate(float a, const glm::vec3& axis) {
        _m = glm::rotate(_m, glm::radians(a), axis);
    }

    void rotate(float, float, float, float);
    void scale(const glm::vec3&);
    void scale(float);
    void scale(float, float, float);

    void mult(const Matrix&) {

    }

    Matrix asRotationMat();
    void invert();
    void transpose();
    void setPerspective(float, float, float, float);
    void setOrtho(float, float, float, float, float, float);
    const float* data() const;
    float* dataNonConst();
    float operator[](int) const;
    const glm::mat4x4& glm() const;
    glm::mat4x4& glmNonConst();

    Matrix operator*(const Matrix& rhs) const {
        _m * rhs._m;
        return *this;
    }

    glm::vec4 operator*(const glm::vec4&) const {

    }

    glm::vec3 operator*(const glm::vec3& v) const {
        return _m * glm::vec4(v, 1.0f);
    }
};