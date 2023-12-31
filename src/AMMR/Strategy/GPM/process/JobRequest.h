// Generated by gencpp from file process/JobRequest.msg
// DO NOT EDIT!


#ifndef PROCESS_MESSAGE_JOBREQUEST_H
#define PROCESS_MESSAGE_JOBREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace process
{
template <class ContainerAllocator>
struct JobRequest_
{
  typedef JobRequest_<ContainerAllocator> Type;

  JobRequest_()
    : id(0)
    , amr_location(0)
    , target_x(0.0)
    , target_y(0.0)
    , target_z(0.0)
    , target_oz(0.0)  {
    }
  JobRequest_(const ContainerAllocator& _alloc)
    : id(0)
    , amr_location(0)
    , target_x(0.0)
    , target_y(0.0)
    , target_z(0.0)
    , target_oz(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _id_type;
  _id_type id;

   typedef int32_t _amr_location_type;
  _amr_location_type amr_location;

   typedef float _target_x_type;
  _target_x_type target_x;

   typedef float _target_y_type;
  _target_y_type target_y;

   typedef float _target_z_type;
  _target_z_type target_z;

   typedef float _target_oz_type;
  _target_oz_type target_oz;





  typedef boost::shared_ptr< ::process::JobRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::process::JobRequest_<ContainerAllocator> const> ConstPtr;

}; // struct JobRequest_

typedef ::process::JobRequest_<std::allocator<void> > JobRequest;

typedef boost::shared_ptr< ::process::JobRequest > JobRequestPtr;
typedef boost::shared_ptr< ::process::JobRequest const> JobRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::process::JobRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::process::JobRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::process::JobRequest_<ContainerAllocator1> & lhs, const ::process::JobRequest_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.amr_location == rhs.amr_location &&
    lhs.target_x == rhs.target_x &&
    lhs.target_y == rhs.target_y &&
    lhs.target_z == rhs.target_z &&
    lhs.target_oz == rhs.target_oz;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::process::JobRequest_<ContainerAllocator1> & lhs, const ::process::JobRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace process

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::process::JobRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::process::JobRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::process::JobRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::process::JobRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::process::JobRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::process::JobRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::process::JobRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "80fdf6b90a9e0b8a9184f88062509ad3";
  }

  static const char* value(const ::process::JobRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x80fdf6b90a9e0b8aULL;
  static const uint64_t static_value2 = 0x9184f88062509ad3ULL;
};

template<class ContainerAllocator>
struct DataType< ::process::JobRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "process/JobRequest";
  }

  static const char* value(const ::process::JobRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::process::JobRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 	id\n"
"int32 	amr_location\n"
"float32 target_x\n"
"float32 target_y\n"
"float32 target_z\n"
"float32 target_oz\n"
;
  }

  static const char* value(const ::process::JobRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::process::JobRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.amr_location);
      stream.next(m.target_x);
      stream.next(m.target_y);
      stream.next(m.target_z);
      stream.next(m.target_oz);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct JobRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::process::JobRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::process::JobRequest_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
    s << indent << "amr_location: ";
    Printer<int32_t>::stream(s, indent + "  ", v.amr_location);
    s << indent << "target_x: ";
    Printer<float>::stream(s, indent + "  ", v.target_x);
    s << indent << "target_y: ";
    Printer<float>::stream(s, indent + "  ", v.target_y);
    s << indent << "target_z: ";
    Printer<float>::stream(s, indent + "  ", v.target_z);
    s << indent << "target_oz: ";
    Printer<float>::stream(s, indent + "  ", v.target_oz);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROCESS_MESSAGE_JOBREQUEST_H
