//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * ����������� ������ PerspectiveCamera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
 * @version 0.1
 * @date 11.09.2006
 */
#ifndef GLA_PerspectiveCamera_h
#define GLA_PerspectiveCamera_h

#include "Camera.h"
namespace Glamour
{
    /// ������������� ������
    /**
     * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
     * @version 0.1
     * @date 11.09.2006
     */
    class PerspectiveCamera: public Camera
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        PerspectiveCamera();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        PerspectiveCamera(const PerspectiveCamera& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        PerspectiveCamera& operator=(const PerspectiveCamera& from);
        ///����������
        ~PerspectiveCamera();
///@}
//==========================================================
///@name ������������
///@{
    PerspectiveCamera(
        const vec3& pos,
        const vec3& dir,
        const vec3& up,
        float _theta,
        float _aspect,
        float _zNear,
        float _zFar);
///@}
//==========================================================
///@name ������
///@{
    virtual void build();
///@}
//==========================================================
///@name �����
///@{
        float theta;
        float aspect;
        float zNear;
        float zFar;
    protected:
    private:
///@}
//==========================================================
    };
}
#endif
