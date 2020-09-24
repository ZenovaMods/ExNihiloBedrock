#pragma once

#include <stack>

#include "Matrix.h"

class MatrixStack {
public:
    class MatrixStackRef {
        MatrixStack* mMatrixStack;
        Matrix* mMatrix;

    public:
        MatrixStackRef() : mMatrixStack(nullptr), mMatrix(nullptr) {}
        MatrixStackRef(MatrixStack& matrixStack, Matrix& matrix) : mMatrixStack(&matrixStack), mMatrix(&matrix) {}

        MatrixStackRef(MatrixStackRef&& msr) {
            _move(std::move(msr));
        }

        ~MatrixStackRef() {
            release();
        }

        void release() {
            if(mMatrixStack) {
                mMatrixStack->mDirty = true;
                mMatrixStack->mStack.pop();
            }

            mMatrixStack = nullptr;
            mMatrix = nullptr;
        }

        Matrix* operator->() {
            mMatrixStack->mDirty = true;
            return mMatrix;
        }

        const Matrix* operator->() const {
            return mMatrix;
        }

        MatrixStackRef& operator=(const Matrix& rhs) {
            *mMatrix = rhs;
            return *this;
        }

        MatrixStackRef& operator=(MatrixStackRef&& rhs) {
            return _move(std::move(rhs));
        }
    
    private:
        MatrixStackRef& _move(MatrixStackRef&& rhs) {
            if(this != &rhs) {
                release();
                mMatrixStack = std::exchange(rhs.mMatrixStack, nullptr);
            }

            return *this;
        }
    };

private:
    std::stack<Matrix> mStack;
    bool mDirty;

public:
    MatrixStack() {
        pushIdentity();
    }

    void pop() {
        mDirty = true;
        mStack.pop();
    }

    MatrixStack::MatrixStackRef push(const Matrix& m) {
        mDirty = true;
        return { *this, _push(m) };
    }

    MatrixStack::MatrixStackRef push() {
        mDirty = true;
        return { *this, _push() };
    }

    MatrixStack::MatrixStackRef pushIdentity() {
        mDirty = true;
        return _pushIdentity();
    }

    bool isDirty() {
        return mDirty;
    }

    void makeClean() {
        mDirty = false;
    }

    glm::mat4 getTop() {
        mDirty = true;
        return top();
    }

    glm::mat4 top() const {
        return mStack.top();
    }

    bool empty() {
        return mStack.empty();
    }

    std::size_t size() const {
        return mStack.size();
    }

private:
    MatrixStack::MatrixStackRef _pushIdentity() {
        return { *this, mStack.emplace() };
    }

    Matrix& _push(const Matrix& m) {
        return mStack.emplace(m);
    }
    
    Matrix& _push() {
        return _push(mStack.top());
    }
};