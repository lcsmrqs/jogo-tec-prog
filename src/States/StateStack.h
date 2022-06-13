/*
 * Baseado no livro SFML Game Development de Artur Moreira, Jan Haller e Henrik Hansson
 */

#pragma once

#include <vector>
#include <list>

namespace States {
	class State;

	class StateStack
	{
	private:
		enum Action
		{
			Push,
			Pop,
            Reset
		};
		struct PendingChange
		{
			Action action;
			State* state;
		};

		std::vector<State*> stateStack;
		std::list<PendingChange> pendingList;

		void applyPendingChanges();

	public:
		StateStack(State *is);
		~StateStack();

		void run(float dt);
		void draw();

		void pushState(State *s);
		void popState();
        void resetTop();

		bool empty();
        const State* getTop() const;
	};
}
