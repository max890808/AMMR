// Generated by gencpp from file airobots_ammr/YoloRequest.msg
// DO NOT EDIT!


#ifndef AIROBOTS_AMMR_MESSAGE_YOLOREQUEST_H
#define AIROBOTS_AMMR_MESSAGE_YOLOREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace airobots_ammr
{
template <class ContainerAllocator>
struct YoloRequest_
{
  typedef YoloRequest_<ContainerAllocator> Type;

  YoloRequest_()
    : id(0)
    , demand(0)  {
    }
  YoloRequest_(const ContainerAllocator& _alloc)
    : id(0)
    , demand(0)  {
  (void)_alloc;
    }



   typedef int32_t _id_type;
  _id_type id;

   typedef int32_t _demand_type;
  _demand_type demand;





  typedef boost::shared_ptr< ::airobots_ammr::YoloRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::airobots_ammr::YoloRequest_<ContainerAllocator> const> ConstPtr;

}; // struct YoloRequest_

typedef ::airobots_ammr::YoloRequest_<std::allocator<void> > YoloRequest;

typedef boost::shared_ptr< ::airobots_ammr::YoloRequest > YoloRequestPtr;
typedef boost::shared_ptr< ::airobots_ammr::YoloRequest const> YoloRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::airobots_ammr::YoloRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::airobots_ammr::YoloRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::airobots_ammr::YoloRequest_<ContainerAllocator1> & lhs, const ::airobots_ammr::YoloRequest_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.demand == rhs.demand;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::airobots_ammr::YoloRequest_<ContainerAllocator1> & lhs, const ::airobots_ammr::YoloRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace airobots_ammr

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::airobots_ammr::YoloRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::airobots_ammr::YoloRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::airobots_ammr::YoloRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "73cab8d826f11c9bdae799e9effb4d74";
  }

  static const char* value(const ::airobots_ammr::YoloRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x73cab8d826f11c9bULL;
  static const uint64_t static_value2 = 0xdae799e9effb4d74ULL;
};

template<class ContainerAllocator>
struct DataType< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "airobots_ammr/YoloRequest";
  }

  static const char* value(const ::airobots_ammr::YoloRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 id\n"
"int32 demand \n"
;
  }

  static const char* value(const ::airobots_ammr::YoloRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.demand);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct YoloRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::airobots_ammr::YoloRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::airobots_ammr::YoloRequest_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
    s << indent << "demand: ";
    Printer<int32_t>::stream(s, indent + "  ", v.demand);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AIROBOTS_AMMR_MESSAGE_YOLOREQUEST_H