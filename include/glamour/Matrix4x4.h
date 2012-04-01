#ifndef GLA_Matrix4x4_h
#define GLA_Matrix4x4_h

#include "Vector3d.h"
namespace Glamour
{
    /** A 4 by 4 matrix 
     *  Such matrices are used to describe three-dimensional transformations.
     *
     *  This class is designed to be OpenGL-compatible, so it uses OpenGL indexing
     *  conventions: column-first, row-second.
     *
     *  The * (multiplication) operator is expecting affine matrices. If the matrix
     *  transforms the fourth coordinate, or if you are not sure if it does, use
     *  the mulMatrix method instead
     *
     *  Use Quaternion objects to create rotation matrices.
     */
    class Matrix4x4
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        /**
         * ������� ��������� �������
         */
        Matrix4x4();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        Matrix4x4(const Matrix4x4& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        Matrix4x4& operator=(const Matrix4x4& from);
        ///����������
        ~Matrix4x4();
///@}
//==========================================================
///@name ������������
///@{
        /// ����������� ������������ �������
        /**
         * @param a �������� ��������� ���������
         */
        Matrix4x4(const float a);
        /// ������������ �����������
        /**
         */
         Matrix4x4(
            const float a00,const float a10,
            const float a20,const float a30,
            const float a01,const float a11,
            const float a21,const float a31,
            const float a02,const float a12,
            const float a22,const float a32,
            const float a03,const float a13,
            const float a23,const float a33);
///@}
//==========================================================
///@name ��������
///@{
    ///������� �������� �� ���� ��������
    /**
     * @param i ���
     * @param j �������
     * @return A[i,j]
     * @note ������� ������ ������������ ������� [0..3]
     * @warning �������� �� ���������� �������� �� ������������ ��������!
     */
    float& element(const int i,const int j);
///@}
//==========================================================
///@name ���������
///@{
    ///������� �������� �� �������
    /**
     * @param i ������ ��������
     * @return ������ �� �������
     * @note ������ ������ ������������ ������� [0..15]
     * @warning �������� �� ���������� �������� �� ������������ �������!
     */
    float& operator[](const int i);
    ///�������������� � ������ ���������
    /**
     * ���������� ����� ������� ������ �������� 16 ��������� � ����� ����
     * ����������� ��� ��� ������, ��� � ��� ������.
     * @return ��������� �� ������� ��� �� ������ �����
     */
    operator float*();
    ///��������� �� �����
    /**
     * @param k �����������
     * @return ��������� ��������
     */
    Matrix4x4& operator*=(const float k);
    ///��������� ���������
    /**
     * @param matrix �������-���������
     * @return ��������� ��������
     */
    Matrix4x4& operator*=(const Matrix4x4& matrix);
    ///��������� �� �����
    /**
     * �����! ����������� �������������, ��� ��������� �������
     * ������ ������ (�.�. w=const).
     * ��� ������ �������� ��������� mulMatrix
     * @param matrix �������-���������
     * @param k �����������
     * @return ��������� ��������
     */
    friend Matrix4x4 operator*(const Matrix4x4& matrix,const float k);
    ///��������� �� �����
    /**
     * @param matrix �������-���������
     * @param k �����������
     * @return ��������� ��������
     */
    friend Matrix4x4 operator*(const float k,const Matrix4x4& matrix);
    ///��������� ���������
    /**
     * @param a �������-���������
     * @param b �������-���������
     * @return ��������� ��������
     */
    friend Matrix4x4 operator*(const Matrix4x4& a,const Matrix4x4& b);
///@}
//==========================================================
///@name ��������
///@{
    ///���������������� ��������������� ������ �������
    void transpose();
    ///���������� ����������������� �������
    /**
     * @return ����������������� �������
     */
    Matrix4x4 getTranspose();
    ///���������� � �������
    /**
     * @param v ������
     * @return ��������������� ������
     * @note �������� �����������, ���� �������
     * �������� ���������� ���������� ������� @i w,
     * ��������, ���� ��� ������� ��������.
     */
    Vector3d applyToVector(const Vector3d& v);
    ///���������� � �����
    /**
     * @param p ������ ��������� �����
     * @return ��������������� �����
     * @note �������� �����������, ���� �������
     * �������� ���������� ���������� ������� @i w,
     * ��������, ���� ��� ������� ��������.
     */
    Vector3d applyToPoint(const Vector3d& p);
    ///���������� � ������� � ������ W
    /**
     * @param v ������
     * @return ��������������� ������
     */
    Vector3d applyToVectorW(const Vector3d& v);
    ///���������� � ����� � ������ W
    /**
     * @param p ������ ��������� �����
     * @return ��������������� �����
     */
    Vector3d applyToPointW(const Vector3d& p);
    ///��������� � GL_PROJECTION
    void setAsGlProjection();
    ///��������� � GL_MODELVIEW
    void setAsGlModelview();
    ///���������� GL_PROJECTION
    void getGlProjection();
    ///���������� GL_MODELVIEW
    void getGlModelview();

    Matrix4x4 mulMatrix(const Matrix4x4& m2);
///@}
//==========================================================
///@name �������
///@{
    ///������� ������� �����������
    /**
     * @param t ������ �����������
     * @return ������� �����������
     */
    static Matrix4x4 createTranslate(const Vector3d& t);
    ///������� ������� ���������������
    /**
     * @param s ������ ���������������
     * @return ������� ���������������
     */
    static Matrix4x4 createScale(const Vector3d& s);
    ///������� ������� �������� ������ ������������ ���
    /**
     * @param a ����
     * @param r ������ ���
     * @return ������� ��������
     */
    //static Matrix4x4 createRotate(const float a,const Vector3d& r);
    ///������� ������� �������� ������ ��� X
    /**
     * @param a ����
     * @return ������� ��������
     */
    static Matrix4x4 createRotateX(const float a);
    ///������� ������� �������� ������ ��� Y
    /**
     * @param a ����
     * @return ������� ��������
     */
    static Matrix4x4 createRotateY(const float a);
    ///������� ������� �������� ������ ��� Z
    /**
     * @param a ����
     * @return ������� ��������
     */
    static Matrix4x4 createRotateZ(const float a);
///@}
//==========================================================
///@name �����
///@{
    protected:
    private:
        float data[16];
///@}
//==========================================================
    };
    ///�������� �������� ���� Matrix4x4
    typedef Matrix4x4 mat4;
}
#endif
