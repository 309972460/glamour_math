//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * ����������� ������ OrthogonalCamera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
 * @version 0.1
 * @date 11.09.2006
 */
#ifndef GLA_OrthogonalCamera_h
#define GLA_OrthogonalCamera_h

#include "Camera.h"
namespace Glamour
{
    /// ������������� ������
    /**
     * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
     * @version 0.1
     * @date 11.09.2006
     */
    class OrthogonalCamera: public Camera
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        OrthogonalCamera();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        OrthogonalCamera(const OrthogonalCamera& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        OrthogonalCamera& operator=(const OrthogonalCamera& from);
        ///����������
        ~OrthogonalCamera();
///@}
//==========================================================
///@name ������������
///@{
    OrthogonalCamera(
        const vec3& pos,
        const vec3& dir,
        const vec3& up,
        const vec3& _min,
        vec3& _max);
    OrthogonalCamera(
        float left,
        float top,
        float right,
        float bottom);
///@}
//==========================================================
///@name ������
///@{
    virtual void build();
///@}
//==========================================================
///@name �����
///@{
        vec3 wMin;
        vec3 wMax;
///@}
//==========================================================
    };
}
#endif
