#pragma once
//std
#include <functional>
#include <memory>

using solution_ptr = std::shared_ptr<class ISolution>;
class ISolution {
public:
	virtual ~ISolution() = default;

	template<typename T>
	static solution_ptr make_solution(size_t problem_id, const std::function<void(T&)>& func) {
		solution_ptr on_insert(new T());
		solutions.emplace(problem_id, std::tuple(on_insert, [func, on_insert] {
			T& obj = *std::dynamic_pointer_cast<T>(on_insert);
			func(obj);
		}));
		return on_insert;
	}

	static void set_active(const size_t& id) { active_id = id; }
	static void exec() {
		const auto& [ptr, func] = solutions[active_id];
		func();
	}

private:
	static size_t active_id;
	static std::unordered_map<size_t, std::tuple<solution_ptr, std::function<void()>>> solutions;
};
