

#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FeatureDetection_Request {
    pub feature: std::string::String,
    pub feature_id: std::string::String,
}



impl Default for FeatureDetection_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::srv::rmw::FeatureDetection_Request::default())
  }
}

impl rosidl_runtime_rs::Message for FeatureDetection_Request {
  type RmwMsg = crate::srv::rmw::FeatureDetection_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feature: msg.feature.as_str().into(),
        feature_id: msg.feature_id.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feature: msg.feature.as_str().into(),
        feature_id: msg.feature_id.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      feature: msg.feature.to_string(),
      feature_id: msg.feature_id.to_string(),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FeatureDetection_Response {
    pub detected: bool,
    pub message: std::string::String,
    pub positions: Vec<geometry_msgs::msg::Point>,
}



impl Default for FeatureDetection_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::srv::rmw::FeatureDetection_Response::default())
  }
}

impl rosidl_runtime_rs::Message for FeatureDetection_Response {
  type RmwMsg = crate::srv::rmw::FeatureDetection_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        detected: msg.detected,
        message: msg.message.as_str().into(),
        positions: msg.positions
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      detected: msg.detected,
        message: msg.message.as_str().into(),
        positions: msg.positions
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      detected: msg.detected,
      message: msg.message.to_string(),
      positions: msg.positions
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
    }
  }
}






#[link(name = "my_robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_robot_interfaces__srv__FeatureDetection() -> *const std::os::raw::c_void;
}

// Corresponds to my_robot_interfaces__srv__FeatureDetection
pub struct FeatureDetection;

impl rosidl_runtime_rs::Service for FeatureDetection {
  type Request = crate::srv::FeatureDetection_Request;
  type Response = crate::srv::FeatureDetection_Response;

  fn get_type_support() -> *const std::os::raw::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_robot_interfaces__srv__FeatureDetection() }
  }
}



pub mod rmw {
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[link(name = "my_robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_robot_interfaces__srv__FeatureDetection_Request() -> *const std::os::raw::c_void;
}

#[link(name = "my_robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn my_robot_interfaces__srv__FeatureDetection_Request__init(msg: *mut FeatureDetection_Request) -> bool;
    fn my_robot_interfaces__srv__FeatureDetection_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FeatureDetection_Request>, size: usize) -> bool;
    fn my_robot_interfaces__srv__FeatureDetection_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FeatureDetection_Request>);
    fn my_robot_interfaces__srv__FeatureDetection_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FeatureDetection_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<FeatureDetection_Request>) -> bool;
}

// Corresponds to my_robot_interfaces__srv__FeatureDetection_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FeatureDetection_Request {
    pub feature: rosidl_runtime_rs::String,
    pub feature_id: rosidl_runtime_rs::String,
}



impl Default for FeatureDetection_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_robot_interfaces__srv__FeatureDetection_Request__init(&mut msg as *mut _) {
        panic!("Call to my_robot_interfaces__srv__FeatureDetection_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FeatureDetection_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_robot_interfaces__srv__FeatureDetection_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_robot_interfaces__srv__FeatureDetection_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_robot_interfaces__srv__FeatureDetection_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FeatureDetection_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FeatureDetection_Request where Self: Sized {
  const TYPE_NAME: &'static str = "my_robot_interfaces/srv/FeatureDetection_Request";
  fn get_type_support() -> *const std::os::raw::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_robot_interfaces__srv__FeatureDetection_Request() }
  }
}


#[link(name = "my_robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_robot_interfaces__srv__FeatureDetection_Response() -> *const std::os::raw::c_void;
}

#[link(name = "my_robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn my_robot_interfaces__srv__FeatureDetection_Response__init(msg: *mut FeatureDetection_Response) -> bool;
    fn my_robot_interfaces__srv__FeatureDetection_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FeatureDetection_Response>, size: usize) -> bool;
    fn my_robot_interfaces__srv__FeatureDetection_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FeatureDetection_Response>);
    fn my_robot_interfaces__srv__FeatureDetection_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FeatureDetection_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<FeatureDetection_Response>) -> bool;
}

// Corresponds to my_robot_interfaces__srv__FeatureDetection_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FeatureDetection_Response {
    pub detected: bool,
    pub message: rosidl_runtime_rs::String,
    pub positions: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,
}



impl Default for FeatureDetection_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_robot_interfaces__srv__FeatureDetection_Response__init(&mut msg as *mut _) {
        panic!("Call to my_robot_interfaces__srv__FeatureDetection_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FeatureDetection_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_robot_interfaces__srv__FeatureDetection_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_robot_interfaces__srv__FeatureDetection_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_robot_interfaces__srv__FeatureDetection_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FeatureDetection_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FeatureDetection_Response where Self: Sized {
  const TYPE_NAME: &'static str = "my_robot_interfaces/srv/FeatureDetection_Response";
  fn get_type_support() -> *const std::os::raw::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_robot_interfaces__srv__FeatureDetection_Response() }
  }
}






  #[link(name = "my_robot_interfaces__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__my_robot_interfaces__srv__FeatureDetection() -> *const std::os::raw::c_void;
  }

  // Corresponds to my_robot_interfaces__srv__FeatureDetection
  pub struct FeatureDetection;

  impl rosidl_runtime_rs::Service for FeatureDetection {
    type Request = crate::srv::rmw::FeatureDetection_Request;
    type Response = crate::srv::rmw::FeatureDetection_Response;

    fn get_type_support() -> *const std::os::raw::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_robot_interfaces__srv__FeatureDetection() }
    }
  }



}  // mod rmw
