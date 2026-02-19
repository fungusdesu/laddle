#pragma once
#include "screens/BaseScreen.hpp"

#include "ui/Spinner.hpp"

constexpr auto TEST_SPINNER_OPTIONS = {"1", "2", "3"};

class SettingsScreen : public BaseScreen
{
public:
	explicit SettingsScreen();

	bool handleInput(const sf::Event &event) override;
	void update() override;
	void draw(sf::RenderTarget &window) const override;

	~SettingsScreen() = default;

private:
	std::unique_ptr<Spinner> p_spinnerPtr;
};