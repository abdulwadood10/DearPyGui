#pragma once

#include <implot.h>
#include <implot_internal.h>
#include "mvAppItem.h"

//-----------------------------------------------------------------------------
// mvTypeBases
//
//     - This file contains abstract classes for concrete mvAppItem 
//       implementations which share common underlying data types.
//     
//-----------------------------------------------------------------------------

namespace Marvel {

	//-----------------------------------------------------------------------------
	// mvIntPtrBase
	//-----------------------------------------------------------------------------
	class mvIntPtrBase : public mvAppItem
	{

	public:

		mvIntPtrBase(const std::string& name, int default_value, const std::string& dataSource);

		~mvIntPtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		int* m_value = nullptr;
		int  m_disabled_value = 0;
	};

	//-----------------------------------------------------------------------------
	// mvInt2PtrBase
	//-----------------------------------------------------------------------------
	class mvInt2PtrBase : public mvAppItem
	{

	public:

		mvInt2PtrBase(const std::string& name, int* default_value, const std::string& dataSource);

		~mvInt2PtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		int* m_value = nullptr;
		int  m_disabled_value[2] {};
	};

	//-----------------------------------------------------------------------------
	// mvInt3PtrBase
	//-----------------------------------------------------------------------------
	class mvInt3PtrBase : public mvAppItem
	{

	public:

		mvInt3PtrBase(const std::string& name, int* default_value, const std::string& dataSource);

		~mvInt3PtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		int* m_value = nullptr;
		int m_disabled_value[3] {};
	};

	//-----------------------------------------------------------------------------
	// mvInt4PtrBase
	//-----------------------------------------------------------------------------
	class mvInt4PtrBase : public mvAppItem
	{

	public:

		mvInt4PtrBase(const std::string& name, int* default_value, const std::string& dataSource);

		~mvInt4PtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		int* m_value = nullptr;
		int  m_disabled_value[4] {};
	};

	//-----------------------------------------------------------------------------
	// mvFloatPtrBase
	//-----------------------------------------------------------------------------
	class mvFloatPtrBase : public mvAppItem
	{

	public:

		mvFloatPtrBase(const std::string& name, float default_value, const std::string& dataSource);

		~mvFloatPtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		float* m_value = nullptr;
		float  m_disabled_value = 0.0;
	};

	//-----------------------------------------------------------------------------
	// mvFloat2PtrBase
	//-----------------------------------------------------------------------------
	class mvFloat2PtrBase : public mvAppItem
	{

	public:

		mvFloat2PtrBase(const std::string& name, float* default_value, const std::string& dataSource);

		~mvFloat2PtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		float* m_value = nullptr;
		float  m_disabled_value[2] {};
	};

	//-----------------------------------------------------------------------------
	// mvFloat3PtrBase
	//-----------------------------------------------------------------------------
	class mvFloat3PtrBase : public mvAppItem
	{

	public:

		mvFloat3PtrBase(const std::string& name, float* default_value, const std::string& dataSource);

		~mvFloat3PtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		float* m_value = nullptr;
		float  m_disabled_value[3] {};
	};

	//-----------------------------------------------------------------------------
	// mvFloat4PtrBase
	//-----------------------------------------------------------------------------
	class mvFloat4PtrBase : public mvAppItem
	{

	public:

		mvFloat4PtrBase(const std::string& name, float* default_value, const std::string& dataSource);

		~mvFloat4PtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		float* m_value = nullptr;
		float  m_disabled_value[4] {};
	};

	//-----------------------------------------------------------------------------
	// mvColorPtrBase
	//-----------------------------------------------------------------------------
	class mvColorPtrBase : public mvAppItem
	{

	public:

		mvColorPtrBase(const std::string& name, float* default_value, const std::string& dataSource);

		~mvColorPtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		float* m_value = nullptr;
	};

	//-----------------------------------------------------------------------------
	// mvBoolPtrBase
	//-----------------------------------------------------------------------------
	class mvBoolPtrBase : public mvAppItem
	{

	public:

		mvBoolPtrBase(const std::string& name, bool default_value, const std::string& dataSource);

		~mvBoolPtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		bool* m_value = nullptr;
		bool  m_disabled_value = false;
	};

	//-----------------------------------------------------------------------------
	// mvStringPtrBase
	//-----------------------------------------------------------------------------
	class mvStringPtrBase : public mvAppItem
	{

	public:

		mvStringPtrBase(const std::string& name, const std::string& default_value, const std::string& dataSource);

		~mvStringPtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		std::string* m_value = nullptr;
		std::string  m_disabled_value = "";
	};

	//-----------------------------------------------------------------------------
	// mvTimePtrBase
	//-----------------------------------------------------------------------------
	class mvTimePtrBase : public mvAppItem
	{

	public:

		mvTimePtrBase(const std::string& name, const tm& default_value, const std::string& dataSource);

		~mvTimePtrBase();

	protected:

		tm*         m_value   = nullptr;
		ImPlotTime* m_imvalue = nullptr;
	};

	//-----------------------------------------------------------------------------
	// mvFloatVectPtrBase
	//-----------------------------------------------------------------------------
	class mvFloatVectPtrBase : public mvAppItem
	{

	public:

		mvFloatVectPtrBase(const std::string& name, const std::vector<float>& default_value, const std::string& dataSource);

		~mvFloatVectPtrBase();

		void setDataSource(const std::string& dataSource) override;

	protected:

		std::vector<float>* m_value = nullptr;
	};

	//-----------------------------------------------------------------------------
	// mvBaseWindowAppitem
	//-----------------------------------------------------------------------------
	class mvBaseWindowAppitem : public mvAppItem
	{

	public:


		mvBaseWindowAppitem(const std::string& name);

		void   addFlag     (ImGuiWindowFlags flag);
		void   removeFlag  (ImGuiWindowFlags flag);
		void   setWindowPos(float x, float y);
		bool   prerender   ();
		mvVec2 getWindowPos() const;

		void setWidth          (int width)      override;
		void setHeight         (int height)     override;
		void setExtraConfigDict(PyObject* dict) override;
		void getExtraConfigDict(PyObject* dict) override;

	protected:

		ImGuiWindowFlags m_windowflags = ImGuiWindowFlags_NoSavedSettings;
		int              m_xpos = 200;
		int              m_ypos = 200;
		bool             m_dirty_pos = true;
		bool             m_dirty_size = true;
	};

}