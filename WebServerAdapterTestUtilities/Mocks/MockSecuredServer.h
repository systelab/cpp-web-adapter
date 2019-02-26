#pragma once

#include "WebServerAdapterInterface/ISecuredServer.h"

#include "WebServerAdapterInterface/IService.h"
#include "WebServerAdapterInterface/Model/Configuration.h"
#include "WebServerAdapterInterface/Model/SecuredServerCredentials.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockSecuredServer : public ISecuredServer
	{
	public:
		MockSecuredServer();
		virtual ~MockSecuredServer();

		MOCK_METHOD1(setConfigurationProxy, void(Configuration*));
		void setConfiguration(std::unique_ptr<Configuration> configuration)
		{
			setConfigurationProxy(configuration.release());
		}

		MOCK_METHOD1(setServerCredentialsProxy, void(SecuredServerCredentials*));
		void setServerCredentials(std::unique_ptr<SecuredServerCredentials> credentials)
		{
			setServerCredentialsProxy(credentials.release());
		}

		MOCK_METHOD1(registerWebServiceProxy, void(IService*));
		void registerWebService(std::unique_ptr<IService> service)
		{
			registerWebServiceProxy(service.release());
		}

		MOCK_CONST_METHOD0(isRunning, bool());
		MOCK_METHOD0(start, void());
		MOCK_METHOD0(stop, void());
	};

}}}

