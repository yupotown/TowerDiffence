
#pragma once

namespace Scene {

class Base {
public:
	Base();
	virtual ~Base();

	// should be implemented
	virtual Base *Update() = 0;
	virtual void Draw() = 0;

	// optional
	virtual void Initialize();
	virtual void Finalize();
	virtual bool Stop();

	// you cannot modify
	bool Kill();
	bool HasFinished();

protected:
	bool finished;

private:
	Base(const Base& rhs);
	const Base& operator =(const Base& rhs);

	bool killed;
};

}
