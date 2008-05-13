#if !defined(OWL_OBJECTPROPERTYUNION_H)
#define OWL_OBJECTPROPERTYUNION_H

#include "IObjectPropertyEntry.h"

#include <vector>

namespace Owl
{
    class RelationMolecule;
    class RelationAtom;
    class RelationRing;
    class RelationBond;
	class RelationDescriptor;

	class ObjectPropertyUnion : public IObjectPropertyEntry
	{

		public:

			ObjectPropertyUnion();
            virtual ~ObjectPropertyUnion();

		private:

			const std::string&									VGetDescription() const;

			bool												VIsLeaf();

			void												VUnionStart();
			bool												VUnionEnd();

			void												VIntersectionStart();
			bool												VIntersectionEnd();

			void												VAddCondition(const std::string& refOn, const std::string& refValue, 
																					const std::string& refOperation);

            
			bool												VSatisfy(RelationDescriptor* pRelDescriptor);
            bool                                                VSatisfy(RelationMolecule* pRelMolecule);
            bool                                                VSatisfy(RelationAtom* pRelAtom);
            bool                                                VSatisfy(RelationBond* pRelBond);
            bool                                                VSatisfy(RelationRing* pRelRing);


		private:

			IObjectPropertyEntry*								m_pCurrentActive;
			
            std::vector<IObjectPropertyEntry*>                  m_vecClassEntries;
	};
}

#endif //!defined(OWL_OBJECTPROPERTYUNION_H)