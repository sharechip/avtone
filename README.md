# avtone
设置/获取动态属性,可用于媒体库权限控制。Set/Get Dynamic Properties. May Apply in Multimedia Access Control


注意事项：
1 动态库的名称不能任意更新，必须为：libavtone.so
2 动态库的接口不能任意更改，需要保持稳定，会被其他库或程序调用（动态库接口见 CrFeature.h）
--------------------------------------------------------------
3 动态的接口稳定情况下，接口的实现可以任意修改，以满足不同的需求。（动态库实现见 CrFeature.cpp）
4 目前仅支持android5.1 及以上版本的系统。


Android 集成方法：
方式A 放置在 android_sdk_root/frameworks/av/media/libstagefright/libavtone 位置，这样系统编译libstatefright时即可编译生成
方式B 放置在 external/libavtone
方式C 讲动态库放置在预编译动态的目录(/vendor/chip_provider/common/vpu/lib/arm/libavtone.so)，然后再Android.mk编写拷贝脚本
