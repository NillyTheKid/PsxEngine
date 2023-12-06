class Core
{
public:
	Core();
	Core(const Core& other) = delete;
	Core(Core&& other) = delete;
	Core& operator=(const Core& other) = delete;
	Core& operator=(Core&& other) = delete;

	void Run();
private:

};