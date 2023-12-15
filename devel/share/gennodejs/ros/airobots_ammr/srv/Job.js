// Auto-generated. Do not edit!

// (in-package airobots_ammr.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class JobRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ammr_location = null;
    }
    else {
      if (initObj.hasOwnProperty('ammr_location')) {
        this.ammr_location = initObj.ammr_location
      }
      else {
        this.ammr_location = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type JobRequest
    // Serialize message field [ammr_location]
    bufferOffset = _serializer.int32(obj.ammr_location, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type JobRequest
    let len;
    let data = new JobRequest(null);
    // Deserialize message field [ammr_location]
    data.ammr_location = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'airobots_ammr/JobRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '00dde7b94c8a24312535a86f6dacc224';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 ammr_location
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new JobRequest(null);
    if (msg.ammr_location !== undefined) {
      resolved.ammr_location = msg.ammr_location;
    }
    else {
      resolved.ammr_location = 0
    }

    return resolved;
    }
};

class JobResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ok = null;
    }
    else {
      if (initObj.hasOwnProperty('ok')) {
        this.ok = initObj.ok
      }
      else {
        this.ok = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type JobResponse
    // Serialize message field [ok]
    bufferOffset = _serializer.int8(obj.ok, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type JobResponse
    let len;
    let data = new JobResponse(null);
    // Deserialize message field [ok]
    data.ok = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'airobots_ammr/JobResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '719c501bbbeb289704ee5d42501844db';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 ok
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new JobResponse(null);
    if (msg.ok !== undefined) {
      resolved.ok = msg.ok;
    }
    else {
      resolved.ok = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: JobRequest,
  Response: JobResponse,
  md5sum() { return '121b506e876d46cc88efd65664c7abde'; },
  datatype() { return 'airobots_ammr/Job'; }
};
