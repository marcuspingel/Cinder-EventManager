//
//  EventDataBase.h
//  RendererTest
//
//  Created by Ryan Bartley on 8/16/14.
//
//

#pragma once
#pragma warning( push )
#pragma warning( disable : 4068 )
/* The classes below are exported */
#pragma GCC visibility push(default)
#pragma warning( pop )

#include <memory>

namespace cinder {
	class Buffer;
}

using EventDataRef = std::shared_ptr<class EventData>;
using EventType = uint64_t;
	
class EventData {
public:
	explicit EventData( float timestamp = 0.0f ) : mTimeStamp( timestamp ), mIsHandled( false ) {}
	virtual ~EventData() = default;

	virtual const char* getName() const = 0;
	virtual EventType getTypeId() const = 0;
	float getTimeStamp() const { return mTimeStamp; }
	
	bool isHandled() const { return mIsHandled; }
	void setIsHandled( bool handled = true ) { mIsHandled = handled; }
	
	virtual void serialize( cinder::Buffer &streamOut ) {}
	virtual void deSerialize( const cinder::Buffer &streamIn ) {}
	virtual EventDataRef copy() { return EventDataRef(); }
	
private:
	const float mTimeStamp;
	bool		mIsHandled;
};

#pragma warning( push )
#pragma warning( disable : 4068 )
#pragma GCC visibility pop
#pragma warning( pop )