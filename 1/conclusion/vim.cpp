PJ_LOG(2,(channel->port.info.name.ptr,
                      "PJMEDIA_VID_STREAM_SKIP_PACKETS_TO_REDUCE_LATENCY = %d ",
                      PJMEDIA_VID_STREAM_SKIP_PACKETS_TO_REDUCE_LATENCY));
LOGERR_((channel->port.info.name.ptr, "PJMEDIA_VID_STREAM_SKIP_PACKETS_TO_REDUCE_LATENCY:", 
                 status));

PJ_LOG(3,(channel->port.info.name.ptr,
                      "can_decode = %d ",
                      can_decode));
LOGERR_((channel->port.info.name.ptr, "can_decode:", 
                 status));

PJ_LOG(4,(channel->port.info.name.ptr,
                      "Don't have frame in buffer"));
LOGERR_((channel->port.info.name.ptr, "error:Don't have frame in buffer"));