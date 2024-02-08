#include <iostream>
#include <cstring>

// More details on the code at:

// https://www.youtube.com/watch?v=LIWbUjHZFTw

#define N_HABITANTS 5

namespace AyED
{
	class Old_McDonals_farm_habitant
	{
	public:
		Old_McDonals_farm_habitant(const char *name) : name_()
		{
			strcpy(name_, name);
		}

		virtual ~Old_McDonals_farm_habitant(void)
		{
		}

		std::ostream &say_hello(std::ostream &os) const
		{
			os << "Hello!! ";
			os << "I'm a ";
			what_I_am(os);
			os << ", my name is ";
			os << name_;
			os << ", and I say ";
			talk(os);
			os << std::endl;

			return os;
		}

		virtual std::ostream &what_I_am(std::ostream &os) const = 0;

		virtual std::ostream &talk(std::ostream &os) const = 0;

	private:
		char name_[80];
	};

	class ground_animal : public Old_McDonals_farm_habitant
	{
	public:
		ground_animal(const char *name, int n_paw) : Old_McDonals_farm_habitant(name),
													 n_paw_(n_paw)
		{
		}

		virtual ~ground_animal(void) {}

	protected:
		int n_paw_;
	};

	class water_animal : public Old_McDonals_farm_habitant
	{
	public:
		water_animal(const char *name) : Old_McDonals_farm_habitant(name)
		{
		}

		virtual ~water_animal(void) {}

		virtual std::ostream &talk(std::ostream &os) const

		{
			os << "glub, glub, ...";

			return os;
		}
	};

	class cow : public ground_animal
	{
	public:
		cow(const char *name) :

								ground_animal(name, 4)
		{
		}

		virtual ~cow(void) {}

		virtual std::ostream &talk(std::ostream &os) const
		{
			os << "muuuuuu, muuuuuuu, ...";

			return os;
		}

		virtual std::ostream &what_I_am(std::ostream &os) const
		{
			os << "black and white cow with " << n_paw_ << " paws";

			return os;
		}
	};

	class chicken : public ground_animal
	{
	public:
		chicken(const char *name) :

									ground_animal(name, 2)
		{
		}

		virtual ~chicken(void) {}

		virtual std::ostream &talk(std::ostream &os) const
		{
			os << "pio, pio, ...";

			return os;
		}

		virtual std::ostream &what_I_am(std::ostream &os) const
		{
			os << "yellow chicken with " << n_paw_ << " paws";

			return os;
		}
	};

	class whale : public water_animal
	{

	public:
		whale(const char *name) :
								  water_animal(name)
		{
		}

		virtual ~whale(void) {}

		virtual std::ostream &what_I_am(std::ostream &os) const
		{
			os << "huge whale";

			return os;
		}
	};

	class shark : public water_animal
	{
	public:
		shark(const char *name) :
								  water_animal(name)
		{
		}

		virtual ~shark(void) {}

		virtual std::ostream &what_I_am(std::ostream &os) const
		{
			water_animal::what_I_am(os);

			os << "hungry shark";

			return os;
		}

		virtual std::ostream &talk(std::ostream &os) const
		{
			os << "ñam, ñam, ...";

			return os;
		}
	};
}

int main(void)
{

	AyED::Old_McDonals_farm_habitant *Old_McDonals_farm[N_HABITANTS];

	Old_McDonals_farm[0] = new AyED::cow("Clotilda");
	Old_McDonals_farm[1] = new AyED::chicken("Chispa");
	Old_McDonals_farm[2] = new AyED::whale("Moby Dick");
	Old_McDonals_farm[3] = new AyED::shark("Dentudo");
	Old_McDonals_farm[4] = new AyED::cow("Blanquita");

	for (int i = 0; i < N_HABITANTS; i++)

		Old_McDonals_farm[i]->say_hello(std::cout);

	for (int i = 0; i < N_HABITANTS; i++)

		if (Old_McDonals_farm[i] != NULL)
		{
			delete Old_McDonals_farm[i];
			Old_McDonals_farm[i] = NULL;
		}

	return 0;
}
